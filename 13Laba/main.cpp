#include <gtkmm.h>
#include <vector>
#include <iostream>
#include <stdexcept>

class MyWindow : public Gtk::Window {
public:
    MyWindow();

private:
    void buttonClicked();
    void sizeButtonClicked();
    bool validateInputs() const;
    void processMatrix();
    void logError(const std::string& message);
    
    // UI Components
    Gtk::Box m_Box;
    Gtk::Label m_Label;
    Gtk::Button m_SolveButton;
    Gtk::Button m_SetSizeButton;
    Gtk::Label m_ResultsLabel;
    Gtk::Entry m_SizeEntry;
    Gtk::Grid m_Grid;
    Gtk::Grid m_ResultsB;
    Gtk::Grid m_ResultsX;
    std::vector<std::vector<Gtk::Entry*>> m_Entries;
    std::vector<std::vector<Gtk::Entry*>> m_EntriesX;
};

MyWindow::MyWindow()
    : m_Box(Gtk::Orientation::VERTICAL),
      m_Label("Введіть розмірність матриці"),
      m_SolveButton("РОЗВ'ЯЗАТИ"),
      m_SetSizeButton("ВСТАНОВИТИ"),
      m_ResultsLabel("") {
    
    // Window setup
    set_title("Матричний калькулятор");
    set_default_size(600, 600);
    
    // Main container setup
    set_child(m_Box);
    m_Box.set_margin(10);
    m_Box.set_spacing(10);
    
    // Add components
    m_Box.append(m_Label);
    m_Box.append(m_SizeEntry);
    m_Box.append(m_SetSizeButton);
    m_Box.append(m_Grid);
    m_Box.append(m_SolveButton);
    m_Box.append(m_ResultsLabel);
    
    // Configure size entry
    m_SizeEntry.set_placeholder_text("Введіть розмір матриці");
    m_SizeEntry.set_max_width_chars(10);
    
    // Configure grid
    m_Grid.set_column_homogeneous(true);
    m_Grid.set_row_homogeneous(true);
    m_Grid.set_row_spacing(5);
    m_Grid.set_column_spacing(5);
    
    // Connect signals
    m_SolveButton.signal_clicked().connect(
        sigc::mem_fun(*this, &MyWindow::buttonClicked));
    m_SetSizeButton.signal_clicked().connect(
        sigc::mem_fun(*this, &MyWindow::sizeButtonClicked));
}

void MyWindow::logError(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
    m_ResultsLabel.set_text("Помилка: " + message);
}

void MyWindow::sizeButtonClicked() {
    try {
        // Clear existing grid (Widgets are automatically removed in GTK 4)
        for (auto& row : m_Entries) {
            for (auto* entry : row) {
                delete entry;  // Directly delete entries for A
            }
        }
        m_Entries.clear();  // Clear the 2D container

        // Clear vector X
        for (auto& row : m_EntriesX) {
            for (auto* entry : row) {
                delete entry;  // Directly delete entries for X
            }
        }
        m_EntriesX.clear();  // Clear the 2D container for X

        // Get and validate size
        int size = std::stoi(m_SizeEntry.get_text());
        if (size <= 0 || size > 5) {
            throw std::invalid_argument("Розмір має бути від 1 до 5");
        }

        // Create new grid
        m_Entries.resize(size, std::vector<Gtk::Entry*>(size));
        m_EntriesX.resize(size, std::vector<Gtk::Entry*>(1));  // Vector X should have 1 column, not rows

        // Create matrix A and attach entries to the grid
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                auto* entry = Gtk::make_managed<Gtk::Entry>();
                entry->set_max_width_chars(8);
                entry->set_placeholder_text("A[" + std::to_string(i) + "][" + std::to_string(j) + "]");
                m_Entries[i][j] = entry;  // Store in the 2D container for A
                m_Grid.attach(*entry, j, i);  // Attach to the grid
                entry->show();  // Show the entry widget
            }
        }

        // Create entries for vector X and attach them in the first column
        for (int i = 0; i < size; ++i) {
            auto* entry = Gtk::make_managed<Gtk::Entry>();
            entry->set_max_width_chars(8);
            entry->set_placeholder_text("X[" + std::to_string(i) + "]");
            m_EntriesX[i][0] = entry;  // Store in the 2D container for X
            m_ResultsX.attach(*entry, 0, i);  // Attach to the first column in the grid
            entry->show();  // Show the entry widget
        }

        // Update the label with the matrix size
        std::cout << "Matrix " << size << "x" << size << " created" << std::endl;
        m_ResultsLabel.set_text("Матриця " + std::to_string(size) + "x" + std::to_string(size) + " створена");

    } catch (const std::exception& e) {
        logError("Error: " + std::string(e.what()));  // Improved error message
    }
}
bool MyWindow::validateInputs() const {
    if (m_Entries.empty()) {
        std::cerr << "Error: Matrix is empty" << std::endl;
        return false;
    }
    
    for (size_t i = 0; i < m_Entries.size(); ++i) {
        for (size_t j = 0; j < m_Entries[i].size(); ++j) {
            const Glib::ustring& text = m_Entries[i][j]->get_text();
            if (text.empty()) {
                std::cerr << "Error: Empty value at position [" << i << "][" << j << "]" << std::endl;
                return false;
            }
            
            try {
                std::stod(text);
            } catch (...) {
                std::cerr << "Error: Invalid number at position [" << i << "][" << j << "]" << std::endl;
                return false;
            }
        }
    }
    return true;
}

void MyWindow::processMatrix() {
    const size_t size = m_Entries.size();
    std::vector<std::vector<double>> matrix(size, std::vector<double>(size));
    
    // Convert entries to numeric matrix
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix[i][j] = std::stod(m_Entries[i][j]->get_text());
        }
    }
    
    // Calculate sum of all elements
    <vector>X_results;
    for (const auto& row : matrix) {
        for (double val : row) {
            X_results[row]+=vector[row][val];
        }
    }

    m_ResultsLabel.set_text("Сума всіх елементів: " + std::to_string(sum));
}

void MyWindow::buttonClicked() {
    if (!validateInputs()) {
        logError("Будь ласка, заповніть всі поля коректними числовими значеннями");
        return;
    }
    
    processMatrix();
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.matrix.calculator");
    return app->make_window_and_run<MyWindow>(argc, argv);
}
