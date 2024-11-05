#include <gtkmm.h>

class MyWindow : public Gtk::Window{
public:
	MyWindow();
private:
	void on_button_clicked();

	Gtk::Box m_VBox;
	Gtk::Label m_Label;
	Gtk::Button m_Button;
	Gtk::ComboBoxText m_ComboBox;
};


MyWindow::MyWindow()
    : m_VBox(Gtk::Orientation::VERTICAL), // Vertical box for stacking widgets
      m_Label("Select an option:"),       // Label text
      m_Button("Click Me")                // Button text
{
    // Set up the window
    set_title("GTKmm Example");
    set_default_size(300, 200);

    // Add the box to the window
    set_child(m_VBox);

    // Add and configure the label
    m_VBox.append(m_Label);

    // Add items to the combo box (dropdown list)
    m_ComboBox.append("x^2 - 4 = 0");
    m_ComboBox.append("3x - 4log(x) - 5 = 0");
    m_ComboBox.set_active(0);  // Set default selection
    m_VBox.append(m_ComboBox);

    // Add and configure the button
    m_Button.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));
    m_VBox.append(m_Button);
}

void MyWindow::on_button_clicked() {
    // Retrieve selected item from the combo box
    Glib::ustring selected_option = m_ComboBox.get_active_text();
    // Update the label based on selection
    m_Label.set_text("You selected: " + selected_option);
}

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.example");
    return app->make_window_and_run<MyWindow>(argc, argv);
}
