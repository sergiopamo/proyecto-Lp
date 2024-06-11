// Clase base Material
class Material {
private:
    std::string titulo_;
    std::string autor_;
    int codigo_;
public:
    Material(const std::string& titulo, const std::string& autor, int codigo)
        : titulo_(titulo), autor_(autor), codigo_(codigo) {}

    virtual void mostrarDetalles() const {
        std::cout << "Título: " << titulo_ << ", Autor: " << autor_ << ", Código: " << codigo_ << std::endl;
    }

};

// Clases derivadas
class Libro : public Material {
private:
    std::string genero_;
public:
    Libro(const std::string& titulo, const std::string& autor, int codigo, const std::string& genero)
        : Material(titulo, autor, codigo), genero_(genero) {}

    void mostrarDetalles() const override {
        Material::mostrarDetalles();
        std::cout << "Género: " << genero_ << std::endl;
    }


};

class Revista : public Material {
private:
    int numero_;
public:
    Revista(const std::string& titulo, const std::string& autor, int codigo, int numero)
        : Material(titulo, autor, codigo), numero_(numero) {}

    void mostrarDetalles() const override {
        Material::mostrarDetalles();
        std::cout << "Número: " << numero_ << std::endl;
    }


};

int main() {
    // Crear objetos de diferentes tipos de materiales
    Libro libro("Nombre del libro", "Autor del libro", 1001, "Genero");
    Revista revista("Nombre de la Revista", "Auyores de la Revista", 2002, 123); // codigo - numero de pagina

    // Crear un arreglo de punteros a Material
    Material* materiales[2];
    materiales[0] = &libro;
    materiales[1] = &revista;

    // Mostrar detalles utilizando polimorfismo
    for (const auto& material : materiales) {
        material->mostrarDetalles();
        std::cout << "--------------------------" << std::endl;
    }

    return 0;
}
