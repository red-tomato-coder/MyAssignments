#include <gtkmm.h>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

class MyWindow : public Gtk::Window {
public:
    MyWindow();

private:
    void sizeButtonClicked();
    void calculateButtonClicked();
    void displayMessage(const std::string& message) const;
    void displayTriangularMatrix(const std::vector<std::vector<double>>& originalMatrix);
    // Helper functions
    void calculateResults();
    double calculateDeterminant(const std::vector<std::vector<double>>& matrix);
    void performForwardElimination(std::vector<std::vector<double>>& A);
    std::vector<std::vector<double>> replaceColumn(const std::vector<std::vector<double>>& matrix, const std::vector<double>& column, int colIndex);
    bool readMatrix(std::vector<std::vector<double>>& A, std::vector<double>& b);

    // UI Components
    Gtk::Grid m_Grid;
    Gtk::Label m_Label;
    Gtk::Label m_Results;
    Gtk::Label m_BLabel;
    Gtk::Button m_SetSizeButton;
    Gtk::Button m_CalculateButton;
    Gtk::Entry m_SizeEntry;
    std::vector<std::vector<Gtk::Entry*>> m_EntriesA;
    std::vector<Gtk::Entry*> m_EntriesB; // For the vector b
    void createMatrixEntries(int size);
};

MyWindow::MyWindow()
    : m_Label("Введіть розмірність матриці"),
      m_SetSizeButton("ВСТАНОВИТИ"),
      m_CalculateButton("РОЗРАХУВАТИ"),
      m_Results(""){

    // Initialize window properties
    set_title("Матричний калькулятор");
    set_default_size(600, 600);

    // Set the grid as the window's child
    set_child(m_Grid);
    m_Grid.set_row_homogeneous(false);
    m_Grid.set_column_homogeneous(true);
    m_Grid.set_row_spacing(15);
    m_Grid.set_column_spacing(15);

    // Add components to the grid
    m_Grid.attach(m_Label, 0, 0, 2, 1);
    m_Grid.attach(m_SizeEntry, 0, 1, 2, 1);
    m_Grid.attach(m_SetSizeButton, 0, 2, 1, 1);
    m_Grid.attach(m_CalculateButton, 1, 2, 1, 1);
    m_Grid.attach(m_Results, 0, 3, 2, 1);

    // Set properties for the size entry
    m_SizeEntry.set_placeholder_text("Введіть розмір матриці");
    m_SizeEntry.set_max_width_chars(10);
    m_SizeEntry.set_margin_bottom(10);

    // Set margins for buttons
    m_SetSizeButton.set_margin_top(10);
    m_CalculateButton.set_margin_top(10);

    // Connect signals
    m_SetSizeButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::sizeButtonClicked));
    m_CalculateButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::calculateButtonClicked));
}

void MyWindow::displayMessage(const std::string& message) const {
    std::cout << message << std::endl;
}

void MyWindow::sizeButtonClicked() {
    try {
        std::cout << "Size button clicked!" << std::endl;

        for (auto& row : m_EntriesA) {
            for (auto* entry : row) {
                m_Grid.remove(*entry);
            }
        }

        for (auto* entry : m_EntriesB) {
            m_Grid.remove(*entry);
        }

        m_EntriesA.clear();
        m_EntriesB.clear();

        int size = std::stoi(m_SizeEntry.get_text());
        if (size <= 0 || size > 5)
            throw std::invalid_argument("Розмір має бути від 1 до 5");

        createMatrixEntries(size);
        std::cout << "Matrix of size " << size << "x" << size << " created." << std::endl;

    } catch (const std::exception& e) {
        displayMessage("Error: " + std::string(e.what()));
    }
}

void MyWindow::createMatrixEntries(int size) {
    m_EntriesA.resize(size, std::vector<Gtk::Entry*>(size));
    m_EntriesB.resize(size);

    for (int i = 0; i < size; ++i) {
        // Create matrix entries for A
        for (int j = 0; j < size; ++j) {
            auto* entry = Gtk::make_managed<Gtk::Entry>();
            entry->set_max_width_chars(8);
            entry->set_placeholder_text("A[" + std::to_string(i) + "][" + std::to_string(j) + "]");
            m_EntriesA[i][j] = entry;
            m_Grid.attach(*entry, j, i + 4, 1, 1);
        }

        // Create entry for b[i]
        auto* entryB = Gtk::make_managed<Gtk::Entry>();
        entryB->set_max_width_chars(8);
        entryB->set_placeholder_text("b[" + std::to_string(i) + "]");
        m_EntriesB[i] = entryB;
        m_Grid.attach(*entryB, size, i + 4, 1, 1);
    }
}

void MyWindow::calculateButtonClicked() {
    m_Results.set_text("");
    std::cout << "Calculate button clicked!" << std::endl;
    calculateResults();
}

void MyWindow::calculateResults() {
    try {
        size_t size = m_EntriesA.size();

        if (size == 0) {
            displayMessage("Matrix size is zero.");
            return;
        }

        if (m_EntriesA.size() != m_EntriesA[0].size()) {
            displayMessage("Matrix is not square. Cramer's Rule requires a square matrix.");
            return;
        }

        // Create the matrix and read its values
        std::vector<std::vector<double>> A(size, std::vector<double>(size));
        std::vector<double> b(size);
        if (!readMatrix(A, b)) return;

        // Calculate row sums
        /*std::vector<double> sum(size, 0);
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < size; ++j) {
                sum[i] += A[i][j];  // Sum up the elements of the i-th row
            }
        }

        Debug output for row sums
        std::cout << "Row sums:" << std::endl;
        for (size_t i = 0; i < size; ++i) {
            m_Results.set_text(m_Results.get_text() + "Sum of row " + std::to_string(i) + ": " + std::to_string(sum[i]) + "\n");
            std::cout << "Sum of row " << i << ": " << sum[i] << std::endl;
        }*/

        double detA = calculateDeterminant(A);
        if (std::abs(detA) < 1e-8) {
            displayMessage("Determinant is zero, no unique solution exists.");
            return;
        }

        // Solve for x using Cramer's Rule
        std::vector<double> x(size);
        for (size_t i = 0; i < size; ++i) {
            std::vector<std::vector<double>> Ai = replaceColumn(A, b, i);
            double detAi = calculateDeterminant(Ai);
            x[i] = detAi / detA;
        }

        // Display the solution
        std::cout << "Solution vector x:" << std::endl;
        for (size_t i = 0; i < size; ++i) {
            m_Results.set_text(m_Results.get_text() + "x[" + std::to_string(i) + "] = " + std::to_string(x[i]) + "\n");
            std::cout << "x[" << i << "] = " << x[i] << std::endl;
        }
        x.clear();
        //sum.clear();
        performForwardElimination(A);
        displayTriangularMatrix(A);
        // Clear vectors

    } catch (const std::exception& e) {
        displayMessage("Error: " + std::string(e.what()));
    }
}


bool MyWindow::readMatrix(std::vector<std::vector<double>>& A, std::vector<double>& b) {
    size_t size = m_EntriesA.size();
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            try {
                A[i][j] = std::stod(m_EntriesA[i][j]->get_text());
            } catch (...) {
                displayMessage("Invalid input at [" + std::to_string(i) + "][" + std::to_string(j) + "].");
                return false;
            }
        }

        try {
            b[i] = std::stod(m_EntriesB[i]->get_text());
        } catch (...) {
            displayMessage("Invalid input for b[" + std::to_string(i) + "].");
            return false;
        }
    }
    return true;
}

double MyWindow::calculateDeterminant(const std::vector<std::vector<double>>& matrix) {
    size_t n = matrix.size();
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double det = 0;
    for (size_t i = 0; i < n; ++i) {
        std::vector<std::vector<double>> subMatrix(n - 1, std::vector<double>(n - 1));
        for (size_t j = 1; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                if (k < i) subMatrix[j - 1][k] = matrix[j][k];
                else if (k > i) subMatrix[j - 1][k - 1] = matrix[j][k];
            }
        }
        det += std::pow(-1, i) * matrix[0][i] * calculateDeterminant(subMatrix);
    }
    return det;
}

std::vector<std::vector<double>> MyWindow::replaceColumn(const std::vector<std::vector<double>>& matrix, const std::vector<double>& column, int colIndex) {
    size_t size = matrix.size();
    std::vector<std::vector<double>> newMatrix = matrix;
    for (size_t i = 0; i < size; ++i) {
        newMatrix[i][colIndex] = column[i];
    }
    return newMatrix;
}

void MyWindow::displayTriangularMatrix(const std::vector<std::vector<double>>& originalMatrix) {
    // Create a copy of the matrix 
    std::vector<std::vector<double>> A = originalMatrix;

    // Perform forward elimination on the copy
    size_t N = A.size();
    for (size_t k = 0; k < N; k++) {
        for (size_t i = k + 1; i < N; i++) {
            if (A[k][k] == 0) continue; // Avoid division by zero
            double factor = A[i][k] / A[k][k];
            for (size_t j = k; j < N; j++) {
                A[i][j] -= factor * A[k][j];
            }
        }
    }

    // Append the triangular matrix to the m_Results label
    m_Results.set_text(m_Results.get_text() + "Triangular Form of Matrix A:\n");
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            if (j < i) {
                // Below diagonal, append 0
                m_Results.set_text(m_Results.get_text() + "0\t");
            } else {
                // Append actual value
                m_Results.set_text(m_Results.get_text() + std::to_string(A[i][j]) + "\t");
            }
        }
        m_Results.set_text(m_Results.get_text() + "\n");
    }
    m_Results.set_text(m_Results.get_text() + "Завершили прямий хід\n");}

void MyWindow::performForwardElimination(std::vector<std::vector<double>>& A) {
    size_t N = A.size();
    
    for (size_t k = 0; k < N; ++k) {
        // Pivoting: Ensure A[k][k] is non-zero by row swapping if necessary
        if (A[k][k] == 0) {
            for (size_t i = k + 1; i < N; ++i) {
                if (A[i][k] != 0) {
                    std::swap(A[k], A[i]);
                    break;
                }
            }
        }
        
        // Ensure diagonal element is non-zero
        if (A[k][k] == 0) {
            m_Results.set_text(m_Results.get_text() + "Cannot proceed: zero pivot at row " + std::to_string(k) + "\n");
            return;
        }

        // Eliminate elements below the pivot
        for (size_t i = k + 1; i < N; ++i) {
            double factor = A[i][k] / A[k][k];
            for (size_t j = k; j < N; ++j) {
                A[i][j] -= factor * A[k][j];
            }
        }
    }
}
int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.myPreciousAtaP13");
    return app->make_window_and_run<MyWindow>(argc, argv);
}
 
