#include <gtkmm.h>
#include <iostream>

class MyWindow : public Gtk::Window {
public:
    MyWindow();

private:
    void buttonClicked();  // Handle "РОЗВ'ЯЗАТИ" button click
    void sizeButtonClicked();  // Handle "ВСТАНОВИТИ" button click
    void add_entry(Gtk::Entry& entry, const Glib::ustring& placeholder);  // Add entry with placeholder

    Gtk::Box m_Box;
    Gtk::Label m_Label;
    Gtk::Button m_Button;
    Gtk::Button m_SizeB;
    Gtk::Label m_Results;
    Gtk::Entry m_Size;
    Gtk::Grid m_Grid;
};

MyWindow::MyWindow()
    : m_Box(Gtk::Orientation::VERTICAL),
      m_Label("ВВЕДІТЬ ДАНІ"),
      m_Button("РОЗВ'ЯЗАТИ"),
      m_SizeB("ВСТАНОВИТИ"),
      m_Results("Результатики >.<") {
    set_title("Козаченко Антон, Обчислення визначеного інтегралу функції 1/(1+x+x^2)");
    set_default_size(400, 400);

    // Set up the layout
    set_child(m_Box);
    m_Box.append(m_Label);

    add_entry(m_Size, "Розмір");  // Add size entry
    m_Box.append(m_SizeB);  // Add "ВСТАНОВИТИ" button
    m_Box.append(m_Button);  // Add "РОЗВ'ЯЗАТИ" button
    m_Box.append(m_Results);

    // Configure the grid
    m_Grid.set_column_homogeneous(true);
    m_Grid.set_row_homogeneous(true);
    m_Box.append(m_Grid);

    // Connect signals
    m_Button.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::buttonClicked));
    m_SizeB.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::sizeButtonClicked));
}

void MyWindow::add_entry(Gtk::Entry& entry, const Glib::ustring& placeholder) {
    entry.set_placeholder_text(placeholder);
    m_Box.append(entry);
}

void MyWindow::sizeButtonClicked() {
    // Clear the grid for new size
    for (auto* child : m_Grid.get_children()) {
        m_Grid.remove(*child);
    }

    // Parse size from entry
    int size = 0;
    try {
        size = std::stoi(m_Size.get_text());
    } catch (...) {
        m_Results.set_text("Некоректний розмір!");
        return;
    }

    if (size <= 0) {
        m_Results.set_text("Розмір має бути більше 0!");
        return;
    }

    // Populate the grid with empty labels
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            auto* label = Gtk::make_managed<Gtk::Label>(std::to_string(i * size + j + 1));
            m_Grid.attach(*label, j, i);  // Attach label at grid cell (column, row)
        }
    }

    // Update results label
    m_Results.set_text("Grid розмір встановлено: " + std::to_string(size) + "x" + std::to_string(size));
}
void MyWindow::buttonClicked() {
    m_Results.set_text("РОЗВ'ЯЗАННЯ ПОЧИНАЄТЬСЯ!");  // Placeholder for solving logic
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.myPreciousAtaP12");
    return app->make_window_and_run<MyWindow>(argc, argv);
}
