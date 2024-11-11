#include <gtkmm.h>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

class MyWindow : public Gtk::Window {
public:
    MyWindow();

private:
    void buttonClicked(); // Make buttonClicked a member function.
    void add_entry(Gtk::Entry& entry, const Glib::ustring& placeholder);
    double midpoint_method(double a, double b, double eps);
    double trapezoid_method(double a, double b, double eps);
    double simpson_method(double a, double b, double eps);
    double montecarlo_method(double a, double b, int N);

    Gtk::Box m_Box;
    Gtk::Label m_Label;
    Gtk::ComboBoxText m_Method;
    Gtk::Entry m_eps;
    Gtk::Entry m_N;
    Gtk::Button m_Button;
    Gtk::Label m_Results;
    Gtk::Entry m_a;
    Gtk::Entry m_b;
};

MyWindow::MyWindow()
    : m_Box(Gtk::Orientation::VERTICAL),
      m_Label("ВВЕДІТЬ ДАНІ"),
      m_Button("РОЗВ'ЯЗАТИ"),
      m_Results("Результатики >.<") {
    set_title("Козаченко Антон, Обчислення визначеного інтегралу функції 1/(1+x+x^2)");
    set_default_size(400, 400);

    // Set up the layout
    set_child(m_Box);
    m_Box.append(m_Label);

    // Add methods to combo box
    m_Method.append("Метод центральних трикутників");
    m_Method.append("Метод трапецій");
    m_Method.append("Метод парабол\\Сімпсона");
    m_Method.append("Монте-Карло");

    // Add entries
    add_entry(m_a, "Введіть а");
    add_entry(m_b, "Введіть b");
    add_entry(m_eps, "Введіть eps");
    add_entry(m_N, "Введіть N");

    // Add widgets to the box
    m_Box.append(m_Method);
    m_Box.append(m_Button);
    m_Box.append(m_Results);

    // Connect the button signal
    m_Button.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::buttonClicked));
}

double MyWindow::midpoint_method(double a, double b, double eps) {
    int N = 1; // Start with a small number of intervals
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N; // Step size
        double sum = 0.0;

        for (int i = 1; i <= N; ++i) {
            double x = a + h * (i - 0.5); // Midpoint of each interval
            sum += 1 / (1 + x + x * x);  // Replace this with f(x)
        }

        result = h * sum;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2; // Double the number of intervals
    }

    return result;
}

double MyWindow::trapezoid_method(double a, double b, double eps) {
    int N = 1; // Start with a small number of intervals
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N; // Step size
        double sum = 0.0;

        for (int i = 1; i < N; ++i) {
            double x = a + i * h; // Internal points
            sum += 1 / (1 + x + x * x);  // Replace this with f(x)
        }

        double fa = 1 / (1 + a + a * a); // f(a)
        double fb = 1 / (1 + b + b * b); // f(b)

        result = h * (fa + fb + 2 * sum) / 2.0;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2; // Double the number of intervals
    }

    return result;
}

double MyWindow::simpson_method(double a, double b, double eps) {
    int N = 2; // Start with a small number of intervals (must be even)
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N; // Step size
        double sum_odd = 0.0, sum_even = 0.0;

        for (int i = 1; i < N; i += 2) {
            double x = a + i * h; // Odd indices
            sum_odd += 1 / (1 + x + x * x); // Replace this with f(x)
        }

        for (int i = 2; i < N; i += 2) {
            double x = a + i * h; // Even indices
            sum_even += 1 / (1 + x + x * x); // Replace this with f(x)
        }

        double fa = 1 / (1 + a + a * a); // f(a)
        double fb = 1 / (1 + b + b * b); // f(b)

        result = h * (fa + fb + 4 * sum_odd + 2 * sum_even) / 6.0;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2; // Double the number of intervals
    }

    return result;
}

double MyWindow::montecarlo_method(double a, double b, int N) {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        double x = a + (b - a) * (static_cast<double>(rand()) / RAND_MAX); // Random x in [a, b]
        sum += 1 / (1 + x + x * x); // Replace with f(x)
    }

    return (b - a) * sum / N;
}

void MyWindow::add_entry(Gtk::Entry& entry, const Glib::ustring& placeholder) {
    entry.set_placeholder_text(placeholder);
    m_Box.append(entry);
}

void MyWindow::buttonClicked() {
    try {
        // Get user inputs
        double a = std::stod(m_a.get_text());
        double b = std::stod(m_b.get_text());
        double eps = std::stod(m_eps.get_text());
        int N = std::stoi(m_N.get_text());

        // Get selected method
        Glib::ustring selected_method = m_Method.get_active_text();

        // Check which method was selected and update results
        if (selected_method == "Метод центральних трикутників") {
            double result = midpoint_method(a, b, eps); // Call your implementation
            m_Results.set_text("Результат методом прямокутників: " + std::to_string(result));
        } else if (selected_method == "Метод трапецій") {
            double result = trapezoid_method(a, b, eps); // Call your implementation
            m_Results.set_text("Результат методом трапецій: " + std::to_string(result));
        } else if (selected_method == "Метод парабол\\Сімпсона") {
            double result = simpson_method(a, b, eps); // Call your implementation
            m_Results.set_text("Результат методом Сімпсона: " + std::to_string(result));
        } else if (selected_method == "Монте-Карло") {
            double result = montecarlo_method(a, b, N); // Call your implementation
            m_Results.set_text("Результат методом Монте-Карло: " + std::to_string(result));
        } else {
            m_Results.set_text("Помилка: оберіть метод інтегрування.");
        }
    } catch (const std::exception& e) {
        // Handle conversion errors or invalid inputs
        m_Results.set_text("Помилка: " + std::string(e.what()));
    }
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.myPreciousAtaP12");
    return app->make_window_and_run<MyWindow>(argc, argv);
}


