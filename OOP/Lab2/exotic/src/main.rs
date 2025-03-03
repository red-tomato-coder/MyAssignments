struct Sphere {
    radius: f64,
}

impl Sphere {

    fn new() -> Self {
        Self { radius: 1.0 }
    }

    fn with_radius(radius: f64) -> Self {
        Self {
            radius: if radius > 0.0 { radius } else { 1.0 },
        }
    }

    fn set_radius(&mut self, new_radius: f64) {
        if new_radius > 0.0 {
            self.radius = new_radius;
        } else {
            self.radius = 1.0;
        }
    }

    fn get_radius(&self) -> f64 {
        self.radius
    }

    fn get_diameter(&self) -> f64 {
        2.0 * self.radius
    }

    fn get_circumference(&self) -> f64 {
        std::f64::consts::PI * self.get_diameter()
    }

    fn get_area(&self) -> f64 {
        4.0 * std::f64::consts::PI * self.radius.powi(2)
    }

    fn get_volume(&self) -> f64 {
        (4.0 / 3.0) * std::f64::consts::PI * self.radius.powi(3)
    }

    fn display_statistics(&self) {
        println!("Радіус = {:.5}", self.get_radius());
        println!("Діаметер = {:.5}", self.get_diameter());
        println!("Довжина = {:.5}", self.get_circumference());
        println!("Площа = {:.5}", self.get_area());
        println!("Обєм = {:.5}", self.get_volume());
    }
}

fn main() {
    let mut sphere = Sphere::new();
    sphere.display_statistics();
    println!("***********");
    let mut custom_sphere = Sphere::with_radius(3.5);
    custom_sphere.display_statistics();
    println!("***********");
    custom_sphere.set_radius(5.0);
    custom_sphere.display_statistics();
}

