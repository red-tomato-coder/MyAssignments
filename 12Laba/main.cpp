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
    // METHODS
    void add_entry(Gtk::Entry& entry, const Glib::ustring& placeholder);
    double midpoint_method(double a, double b, double eps, int& N);
    double trapezoid_method(double a, double b, double eps, int& N);
    double simpson_method(double a, double b, double eps, int& N);
    double montecarlo_method(double a, double b, int N);
    double midpoint_method_advanced(double a, double b, double eps, int& N);
    double trapezoid_method_advanced(double a, double b, double eps, int& N);
    double simpson_method_advanced(double a, double b, double eps, int& N);
    double montecarlo_method_advanced(double a, double b, int N);
    double findM(double a, double b, int N);
    double findM_advanced(double a, double b, int N);    
    int genPoints(double a, double b, int N);
    int genPoints_advanced(double a, double b, int N);
    //STEPS
    int midpoint_steps(double a, double b, double eps);
    int trapezoid_steps(double a, double b, double eps);
    int simpson_steps(double a, double b, double eps);
    int midpoint_steps_advanced(double a, double b, double eps);
    int montecarlo_steps_advanced(double a, double b, int N);
    int trapezoid_steps_advanced(double a, double b, double eps);
    int simpson_steps_advanced(double a, double b, double eps);



    Gtk::Box m_Box;
    Gtk::Label m_Label;
    Gtk::ComboBoxText m_Method;
    Gtk::Entry m_eps;
    Gtk::Entry m_N;
    Gtk::Button m_Button;
    Gtk::Label m_Results;
    Gtk::Entry m_a;
    Gtk::Entry m_b;
};MyWindow::MyWindow()
    : m_Box(Gtk::Orientation::VERTICAL),
      m_Label("ВВЕДІТЬ ДАНІ"),
      m_Button("РОЗВ'ЯЗАТИ"),
      m_Results("Результати\n") {
    set_title("Козаченко Антон, Обчислення визначеного інтегралу функції 1/(1+x+x^2)");
    set_default_size(400, 400);

    // Set up the layout
    set_child(m_Box);
    m_Box.append(m_Label);

    // Add methods to combo box
    m_Method.append("1/(1+x+x^2)");
    m_Method.append("x^3+3x^2x+1"); 

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

double MyWindow::midpoint_method(double a, double b, double eps, int& N) {
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum = 0.0;

        for (int i = 1; i <= N; ++i) {
            double x = a + h * (i - 0.5);
            sum += 1 / (1 + x + x * x);
        }

        result = h * sum;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2; // Double the number of intervals
    }

    return result;
}

double MyWindow::trapezoid_method(double a, double b, double eps, int& N) {
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum = 0.0;

        for (int i = 1; i < N; ++i) {
            double x = a + i * h;
            sum += 1 / (1 + x + x * x);
        }

        double fa = 1 / (1 + a + a * a);
        double fb = 1 / (1 + b + b * b);

        result = h * (fa + fb + 2 * sum) / 2.0;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2;
    }

    return result;
}

double MyWindow::simpson_method(double a, double b, double eps, int& N) {
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum_odd = 0.0, sum_even = 0.0;

        for (int i = 1; i < N; i += 2) {
            double x = a + i * h;
            sum_odd += 1 / (1 + x + x * x);
        }

        for (int i = 2; i < N; i += 2) {
            double x = a + i * h;
            sum_even += 1 / (1 + x + x * x);
        }

        double fa = 1 / (1 + a + a * a);
        double fb = 1 / (1 + b + b * b);

        result = h * (fa + fb + 4 * sum_odd + 2 * sum_even) / 6.0;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2;
    }

    return result;
}

double MyWindow::findM(double a, double b, int N) {
    double M = -std::numeric_limits<double>::infinity();
    for (double x = a; x <= b; x += (b - a) / N) {
        double y = 1 / (1 + x + x * x);
        if (y > M) {
            M = y;
        }
    }
    return M;
}

int MyWindow::genPoints(double a, double b, int N) {
    int Nb = 0;
    srand(static_cast<unsigned>(time(0)));
    double M = findM(a, b, N); // Precompute M
    for (int i = 0; i < N; i++) {
        double x_rand = a + (static_cast<double>(std::rand()) / RAND_MAX) * (b - a);
        double y_rand = (static_cast<double>(std::rand()) / RAND_MAX) * M;
        if (y_rand <= (1 / (1 + x_rand + x_rand * x_rand))) {
            Nb++;
        }
    }
    return Nb;
}

double MyWindow::montecarlo_method(double a, double b, int N) {
    double M = findM(a, b, N);
    double S = M * (b - a); // Total area of bounding rectangle
    int Nb = genPoints(a, b, N); // Points under the curve
    return S * (static_cast<double>(Nb) / N);
}

int MyWindow::midpoint_steps(double a, double b, double eps) {
    int N = 1;
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum = 0.0;

        for (int i = 1; i <= N; ++i) {
            double x = a + h * (i - 0.5);
            sum += 1 / (1 + x + x * x);
        }

        result = h * sum;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2; // Double the number of intervals
    }

    return steps;
}

int MyWindow::trapezoid_steps(double a, double b, double eps) {
    int N = 1;
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum = 0.0;

        for (int i = 1; i < N; ++i) {
            double x = a + i * h;
            sum += 1 / (1 + x + x * x);
        }

        double fa = 1 / (1 + a + a * a);
        double fb = 1 / (1 + b + b * b);

        result = h * (fa + fb + 2 * sum) / 2.0;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2;
    }

    return steps;
}

int MyWindow::simpson_steps(double a, double b, double eps) {
    int N = 2;  // Start with a small number of intervals (must be even)
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum_odd = 0.0, sum_even = 0.0;

        for (int i = 1; i < N; i += 2) {
            double x = a + i * h;
            sum_odd += 1 / (1 + x + x * x);
        }

        for (int i = 2; i < N; i += 2) {
            double x = a + i * h;
            sum_even += 1 / (1 + x + x * x);
        }

        double fa = 1 / (1 + a + a * a);
        double fb = 1 / (1 + b + b * b);

        result = h * (fa + fb + 4 * sum_odd + 2 * sum_even) / 6.0;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2;
    }

    return steps;
}

double MyWindow::midpoint_method_advanced(double a, double b, double eps, int& N) {
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum = 0.0;

        for (int i = 1; i <= N; ++i) {
            double x = a + h * (i - 0.5);
            sum += std::pow(x, 3) + 3 * std::pow(x, 2) + 2 * x + 1;
        }

        result = h * sum;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2; // Double the number of intervals
    }

    return result;
}

double MyWindow::trapezoid_method_advanced(double a, double b, double eps, int& N) {
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum = 0.0;

        for (int i = 1; i < N; ++i) {
            double x = a + i * h;
            sum += std::pow(x, 3) + 3 * std::pow(x, 2) + 2 * x + 1;
        }

        double fa = std::pow(a, 3) + 3 * std::pow(a, 2) + 2 * a + 1;
        double fb = std::pow(b, 3) + 3 * std::pow(b, 2) + 2 * b + 1;

        result = h * (fa + fb + 2 * sum) / 2.0;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2;
    }

    return result;
}

double MyWindow::simpson_method_advanced(double a, double b, double eps, int& N) {
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum_odd = 0.0, sum_even = 0.0;

        for (int i = 1; i < N; i += 2) {
            double x = a + i * h;
            sum_odd += std::pow(x, 3) + 3 * std::pow(x, 2) + 2 * x + 1;
        }

        for (int i = 2; i < N; i += 2) {
            double x = a + i * h;
            sum_even += std::pow(x, 3) + 3 * std::pow(x, 2) + 2 * x + 1;
        }

        double fa = std::pow(a, 3) + 3 * std::pow(a, 2) + 2 * a + 1;
        double fb = std::pow(b, 3) + 3 * std::pow(b, 2) + 2 * b + 1;

        result = h * (fa + fb + 4 * sum_odd + 2 * sum_even) / 6.0;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2;
    }

    return result;
}

double MyWindow::findM_advanced(double a, double b, int N) {
    double M = -std::numeric_limits<double>::infinity();
    for (double x = a; x <= b; x += (b - a) / N) {
        double y = std::pow(x, 3) + 3 * std::pow(x, 2) + 2 * x + 1;
        if (y > M) {
            M = y;
        }
    }
    return M;
}

int MyWindow::genPoints_advanced(double a, double b, int N) {
    int Nb = 0;
    srand(static_cast<unsigned>(time(0)));
    double M = findM_advanced(a, b, N); // Precompute M
    for (int i = 0; i < N; i++) {
        double x_rand = a + (static_cast<double>(std::rand()) / RAND_MAX) * (b - a);
        double y_rand = (static_cast<double>(std::rand()) / RAND_MAX) * M;
        if (y_rand <= (std::pow(x_rand, 3) + 3 * std::pow(x_rand, 2) + 2 * x_rand + 1)) {
            Nb++;
        }
    }
    return Nb;
}

double MyWindow::montecarlo_method_advanced(double a, double b, int N) {
    double M = findM_advanced(a, b, N);
    double S = M * (b - a); // Total area of bounding rectangle
    int Nb = genPoints_advanced(a, b, N); // Points under the curve
    return S * (static_cast<double>(Nb) / N);
}

int MyWindow::montecarlo_steps_advanced(double a, double b, int N) {
    int steps = 0;
    srand(static_cast<unsigned>(time(0)));
    double M = findM_advanced(a, b, N); // Precompute M
    double S = M * (b - a); // Area of bounding rectangle

    for (int i = 0; i < N; ++i) {
        double x_rand = a + (static_cast<double>(std::rand()) / RAND_MAX) * (b - a);
        double y_rand = (static_cast<double>(std::rand()) / RAND_MAX) * M;
        if (y_rand <= (std::pow(x_rand, 3) + 3 * std::pow(x_rand, 2) + 2 * x_rand + 1)) {
            steps++;
        }
    }

    // Return the ratio of points under the curve (which is the estimate of the integral)
    return steps;
}

int MyWindow::midpoint_steps_advanced(double a, double b, double eps) {
    int N = 1;
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum = 0.0;

        for (int i = 1; i <= N; ++i) {
            double x = a + h * (i - 0.5);
            sum += std::pow(x, 3) + 3 * std::pow(x, 2) + 2 * x + 1;
        }

        result = h * sum;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2; // Double the number of intervals
    }

    return steps;
}

int MyWindow::trapezoid_steps_advanced(double a, double b, double eps) {
    int N = 1;
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum = 0.0;

        for (int i = 1; i < N; ++i) {
            double x = a + i * h;
            sum += std::pow(x, 3) + 3 * std::pow(x, 2) + 2 * x + 1;
        }

        double fa = std::pow(a, 3) + 3 * std::pow(a, 2) + 2 * a + 1;
        double fb = std::pow(b, 3) + 3 * std::pow(b, 2) + 2 * b + 1;

        result = h * (fa + fb + 2 * sum) / 2.0;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2;
    }

    return steps;
}

int MyWindow::simpson_steps_advanced(double a, double b, double eps) {
    int N = 2;  // Start with a small number of intervals (must be even)
    int steps = 0;
    double prev_result = std::numeric_limits<double>::infinity();
    double result = 0.0;

    while (true) {
        double h = (b - a) / N;
        double sum_odd = 0.0, sum_even = 0.0;

        for (int i = 1; i < N; i += 2) {
            double x = a + i * h;
            sum_odd += std::pow(x, 3) + 3 * std::pow(x, 2) + 2 * x + 1;
        }

        for (int i = 2; i < N; i += 2) {
            double x = a + i * h;
            sum_even += std::pow(x, 3) + 3 * std::pow(x, 2) + 2 * x + 1;
        }

        double fa = std::pow(a, 3) + 3 * std::pow(a, 2) + 2 * a + 1;
        double fb = std::pow(b, 3) + 3 * std::pow(b, 2) + 2 * b + 1;

        result = h * (fa + fb + 4 * sum_odd + 2 * sum_even) / 6.0;
        steps++;

        if (std::abs(result - prev_result) < eps) {
            break;
        }

        prev_result = result;
        N *= 2;  // Double the number of intervals
    }

    return steps;
}
void MyWindow::add_entry(Gtk::Entry& entry, const Glib::ustring& placeholder) {
    entry.set_placeholder_text(placeholder);
    m_Box.append(entry);
}

void MyWindow::buttonClicked() {
    m_Results.set_text("РЕЗУЛЬТАТ:\n");
    try {
      double a = std::stod(m_a.get_text());
        double b = std::stod(m_b.get_text());
        double eps = std::stod(m_eps.get_text());
        int N = std::stoi(m_N.get_text());

        // Calculate results for each method and keep track of the steps
        double result;
        int steps = 0;
        if(m_Method.get_active_text() == "1/(1+x+x^2)"){
        // Midpoint Method
        result = midpoint_method(a, b, eps, N);
        steps = midpoint_steps(a, b, eps); 
        m_Results.set_text(m_Results.get_text() + "Метод центральних трикутників: " + std::to_string(result) + " за " + std::to_string(steps) + " кроків\n");

        // Trapezoid Method
        result = trapezoid_method(a, b, eps, N);
        steps = trapezoid_steps(a, b, eps); 
        m_Results.set_text(m_Results.get_text() + "Метод трапецій: " + std::to_string(result) + " за " + std::to_string(steps) + " кроків\n");

        // Simpson Method
        result = simpson_method(a, b, eps, N);
        steps = simpson_steps(a, b, eps); 
        m_Results.set_text(m_Results.get_text() + "Метод парабол\\Сімпсона: " + std::to_string(result) + " за " + std::to_string(steps) + " кроків\n");

        // Monte Carlo Method
        result = montecarlo_method(a, b, N); // For Monte Carlo, N is used directly, not epsilon
        steps = N; // No iterations in the classic sense for Monte Carlo
        m_Results.set_text(m_Results.get_text() + "Метод Монте-Карло: " + std::to_string(result) + " за " + std::to_string(steps) + " кроків\n");
    }
        if(m_Method.get_active_text() == "x^3+3x^2x+1") {
    // Midpoint Method
    result = midpoint_method_advanced(a, b, eps, N);
    steps = midpoint_steps(a, b, eps); 
    m_Results.set_text(m_Results.get_text() + "Метод центральних трикутників: " + std::to_string(result) + " за " + std::to_string(steps) + " кроків\n");

    // Trapezoid Method
    result = trapezoid_method_advanced(a, b, eps, N);
    steps = trapezoid_steps(a, b, eps); 
    m_Results.set_text(m_Results.get_text() + "Метод трапецій: " + std::to_string(result) + " за " + std::to_string(steps) + " кроків\n");

    // Simpson Method
    result = simpson_method_advanced(a, b, eps, N);
    steps = simpson_steps(a, b, eps); 
    m_Results.set_text(m_Results.get_text() + "Метод парабол\\Сімпсона: " + std::to_string(result) + " за " + std::to_string(steps) + " кроків\n");

    // Monte Carlo Method
    result = montecarlo_method_advanced(a, b, N); // For Monte Carlo, N is used directly, not epsilon
    steps = N; // No iterations in the classic sense for Monte Carlo
    m_Results.set_text(m_Results.get_text() + "Метод Монте-Карло: " + std::to_string(result) + " за " + std::to_string(steps) + " кроків\n");
}
    } 
    catch (const std::exception& e) {
        // Handle conversion errors or invlid inputs
        m_Results.set_text("Помилка: " + std::string(e.what()));
    }
}int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.myPreciousAtaP12");
    return app->make_window_and_run<MyWindow>(argc, argv);
}

