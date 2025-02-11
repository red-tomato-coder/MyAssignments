//Боже, пробач, не відає твоє дитя, що воно творить
#include <gtkmm.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

class MyWindow : public Gtk::Window {
public:
    MyWindow();
private:
    void on_button_clicked();
    
    void add_entry(Gtk::Entry& entry, const Glib::ustring& placeholder);
    int easyBisection(double a, double b, double eps, int kmax);
    int hardBisection(double a, double b, double eps, int kmax);
    int specialBisection(double a, double b, double eps, int kmax);
    int specialNewton(double a, double b, double eps, int kmax);
    int easyNewton(double a, double b, double eps, int kmax);
    int hardNewton(double a, double b, double eps, int kmax);
    double f1(double x) { return pow(x, 2)-4; } 
    double f2(double x) { return 3 * x - 4 * log(x) - 5; }
    double f3(double x) { return 1/x-1; }
    double fp1(double x) { return 2 * x; } 
    double fp2(double x) { return 3 - 4 / x; }
    double fp3(double x) { return -1/pow(x, 2); }

    Gtk::Box m_VBox;
    Gtk::Label m_Label;
    Gtk::Button m_Button;
    Gtk::ComboBoxText m_Equation;
    Gtk::ComboBoxText m_Method;
    Gtk::Entry m_a;
    Gtk::Entry m_b;
    Gtk::Entry m_eps;
    Gtk::Entry m_kmax;
    Gtk::Label m_x;
    Gtk::Label m_iterations;
};

MyWindow::MyWindow()
    : m_VBox(Gtk::Orientation::VERTICAL), 
      m_Label("ВИБЕРІТЬ РІВНЯННЯ"),       
      m_Button("ВИРІШИТИ"),
      m_x("X: "),
      m_iterations("Iterations: ")
{
    set_title("Козаченко Розв’язання нелінійних рівнянь за МДП та МН.");
    set_default_size(300, 200);
    set_child(m_VBox);
    m_VBox.append(m_Label);
    m_Equation.append("x^2 - 4 = 0");
    m_Equation.append("3x - 4log(x) - 5 = 0");
    m_Equation.append("1/x-1");
    m_Equation.set_active(0);  
    m_Method.append("Бісекція");
    m_Method.append("Ньютон");
    m_Method.set_active(0);
    m_VBox.append(m_Equation);
    m_VBox.append(m_Method);
    add_entry(m_a, "Enter a");
    add_entry(m_b, "Enter b");
    add_entry(m_eps, "Enter ε (epsilon)");
    add_entry(m_kmax, "Enter kmax");
    m_VBox.append(m_x);
    m_VBox.append(m_iterations); 
    m_Button.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));
    m_VBox.append(m_Button);
}

void MyWindow::add_entry(Gtk::Entry& entry, const Glib::ustring& placeholder) {
    entry.set_placeholder_text(placeholder);
    m_VBox.append(entry);
}

int MyWindow::easyBisection(double a, double b, double eps, int kmax) {
    int count = 0;

    // Check if the root is at the initial endpoints
    if (f1(a) == 0.0) {
        m_x.set_text("Root: " + std::to_string(a));
        m_iterations.set_text("Iterations: " + std::to_string(count));
        return 0;
    }
    if (f1(b) == 0.0) {
        m_x.set_text("Root: " + std::to_string(b));
        m_iterations.set_text("Iterations: " + std::to_string(count));
        return 0;
    }

    if (f1(a) * f1(b) > 0) {
        std::cerr << "No guarantee that roots are found in the given range for easy Bisection." << std::endl;
        m_x.set_text("Error: Function values at endpoints do not have opposite signs.");
        m_iterations.set_text("Iterations: N/A");
        return -1;
    }

    double mid, Fc;
    while (count < kmax) {
        mid = (a + b) / 2.0;
        Fc = f1(mid);

        // Check if root is at the midpoint
        if (Fc == 0.0 || std::abs(b - a) < eps) {
            m_x.set_text("Root: " + std::to_string(mid));
            m_iterations.set_text("Iterations: " + std::to_string(count));
            return 0;
        }

        // Apply the bisection method
        if (f1(a) * Fc < 0) {
            b = mid;
        } else {
            a = mid;
        }

        count++;
    }

    std::cerr << "For the given number of iterations, no root was found with Eps precision." << std::endl;
    m_x.set_text("Error: Maximum iterations reached without finding a root.");
    m_iterations.set_text("Iterations: " + std::to_string(count));
    return -1;
}

int MyWindow::hardBisection(double a, double b, double eps, int kmax) {
    int count = 0;

    // Check domain validity first (x must be positive due to ln(x))
    if (a <= 0 || b <= 0) {
        std::cerr << "Error: Domain error. Both endpoints must be positive for ln(x)." << std::endl;
        m_x.set_text("Error: Invalid domain. Values must be positive.");
        m_iterations.set_text("Iterations: N/A");
        return -1;
    }

    if (f2(a) * f2(b) >= 0) {
        std::cerr << "No guarantee that roots are found in the given range for hard Bisection." << std::endl;
        m_x.set_text("Error: Function values at endpoints do not have opposite signs.");
        m_iterations.set_text("Iterations: N/A");
        return -1;
    }

    double mid, Fc;
    while (count < kmax) {
        mid = (a + b) / 2.0;
        Fc = f2(mid);

        // Check if root is at the midpoint with appropriate precision
        if (std::abs(Fc) < eps || std::abs(b - a) < eps) {
            m_x.set_text("Root: " + std::to_string(mid));
            m_iterations.set_text("Iterations: " + std::to_string(count));
            return 0;
        }

        // Apply the bisection method
        if (f2(a) * Fc < 0) {
            b = mid;
        } else {
            a = mid;
        }

        count++;
    }

    std::cerr << "For the given number of iterations, no root was found with Eps precision." << std::endl;
    m_x.set_text("Error: Maximum iterations reached without finding a root.");
    m_iterations.set_text("Iterations: " + std::to_string(count));
    return -1;
}

int MyWindow::specialBisection(double a, double b, double eps, int kmax){
    int count = 0;

    // Check domain validity first (x must be positive due to ln(x))
    if (a <= 0 || b <= 0) {
        std::cerr << "Error: Domain error. Both endpoints must be positive for ln(x)." << std::endl;
        m_x.set_text("Error: Invalid domain. Values must be positive.");
        m_iterations.set_text("Iterations: N/A");
        return -1;
    }

    if (f3(a) * f3(b) >= 0) {
        std::cerr << "No guarantee that roots are found in the given range for hard Bisection." << std::endl;
        m_x.set_text("Error: Function values at endpoints do not have opposite signs.");
        m_iterations.set_text("Iterations: N/A");
        return -1;
    }

    double mid, Fc;
    while (count < kmax) {
        mid = (a + b) / 2.0;
        Fc = f3(mid);

        // Check if root is at the midpoint with appropriate precision
        if (std::abs(Fc) < eps || std::abs(b - a) < eps) {
            m_x.set_text("Root: " + std::to_string(mid));
            m_iterations.set_text("Iterations: " + std::to_string(count));
            return 0;
        }

        // Apply the bisection method
        if (f3(a) * Fc < 0) {
            b = mid;
        } else {
            a = mid;
        }

        count++;
    }

    std::cerr << "For the given number of iterations, no root was found with Eps precision." << std::endl;
    m_x.set_text("Error: Maximum iterations reached without finding a root.");
    m_iterations.set_text("Iterations: " + std::to_string(count));
    return -1;
}


int MyWindow::easyNewton(double a, double b, double eps, int kmax) {
    double x = b; 
    int count = 0;

    if (fp1(x) == 0) {
        std::cerr << "Unable to calculate the derivative. Try a different interval." << std::endl;
        m_x.set_text("Error: Derivative is zero.");
        m_iterations.set_text("Iterations: N/A");
        return -1; 
    }

    for (int i = 0; i < kmax; i++) {
        double dx = f1(x) / fp1(x);
        x -= dx;
        count++;

        if (std::abs(dx) <= eps) {
            std::cout << "Root: " << x << ", Iterations: " << count << std::endl;
            m_x.set_text("Root: " + std::to_string(x));
            m_iterations.set_text("Iterations: " + std::to_string(count));
            return 0; 
        }
    }

    std::cerr << "For the given number of iterations, no root was found with Eps precision." << std::endl;
    return -1; 
}

int MyWindow::hardNewton(double a, double b, double eps, int kmax) {
    double x = b; 
    int count = 0;

    if (fp2(x) == 0) {
        std::cerr << "Unable to calculate the derivative. Try a different interval." << std::endl;
        m_x.set_text("Error: Derivative is zero.");
        m_iterations.set_text("Iterations: N/A");
        return -1; 
    }

    for (int i = 0; i < kmax; i++) {
        double dx = f2(x) / fp2(x);
        x -= dx;
        count++;

        if (std::abs(dx) <= eps) {
            std::cout << "Root: " << x << ", Iterations: " << count << std::endl;
            m_x.set_text("Root: " + std::to_string(x));
            m_iterations.set_text("Iterations: " + std::to_string(count));
            return 0; 
        }
    }

    std::cerr << "For the given number of iterations, no root was found with Eps precision." << std::endl;
    return -1; 
}

int MyWindow::specialNewton(double a, double b, double eps, int kmax) {
    double x = b; 
    int count = 0;

    if (fp3(x) == 0) {
        std::cerr << "Unable to calculate the derivative. Try a different interval." << std::endl;
        m_x.set_text("Error: Derivative is zero.");
        m_iterations.set_text("Iterations: N/A");
        return -1; 
    }

    for (int i = 0; i < kmax; i++) {
        double dx = f3(x) / fp3(x);
        x -= dx;
        count++;

        if (std::abs(dx) <= eps) {
            std::cout << "Root: " << x << ", Iterations: " << count << std::endl;
            m_x.set_text("Root: " + std::to_string(x));
            m_iterations.set_text("Iterations: " + std::to_string(count));
            return 0; 
        }
    }

    std::cerr << "For the given number of iterations, no root was found with Eps precision." << std::endl;
    return -1; 
}

void MyWindow::on_button_clicked() {
    // Your logic for when the button is clicked
    // For example, perform the selected equation and method calculation
    double a = std::stod(m_a.get_text());
    double b = std::stod(m_b.get_text());
    double eps = std::stod(m_eps.get_text());
    int kmax = std::stoi(m_kmax.get_text());

    // Example: Check the selected method and equation
    if (m_Method.get_active_text() == "Бісекція") {
        if (m_Equation.get_active_text() == "x^2 - 4 = 0") {
            easyBisection(a, b, eps, kmax);
        } else if (m_Equation.get_active_text() == "3x - 4log(x) - 5 = 0") {
            hardBisection(a, b, eps, kmax);
        }
          else if(m_Equation.get_active_text() == "1/x-1"){
            specialBisection(a, b, eps, kmax);
          }
    } else if (m_Method.get_active_text() == "Ньютон") {
        if (m_Equation.get_active_text() == "x^2 - 4 = 0") {
            easyNewton(a, b, eps, kmax);
        } else if (m_Equation.get_active_text() == "3x - 4log(x) - 5 = 0") {
            hardNewton(a, b, eps, kmax);}
          else if(m_Equation.get_active_text() == "1/x-1"){
            specialNewton(a, b, eps, kmax);
          }
    }
}


int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.myPreciousAtaP");
    return app->make_window_and_run<MyWindow>(argc, argv);
}
