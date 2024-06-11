#include <iostream>
#include <string>
using namespace std;

// Clase base Material
class Material {
private:
    string titulo_;
    string autor_;
    int codigo_;
public:
    Material(const string& titulo, const string& autor, int codigo)
        : titulo_(titulo), autor_(autor), codigo_(codigo) {}

    virtual void mostrarDetalles() const {
        cout << "Título: " << titulo_ << ", Autor: " << autor_ << ", Código: " << codigo_ << endl;
    }

};

// Clases derivadas
class Libro : public Material {
private:
    string genero_;
public:
    Libro(const string& titulo, const string& autor, int codigo, const string& genero)
        : Material(titulo, autor, codigo), genero_(genero) {}

    void mostrarDetalles() const override {
        Material::mostrarDetalles();
        cout << "Género: " << genero_ << endl;
    }


};

class Revista : public Material {
private:
    int numero_;
public:
    Revista(const string& titulo, const string& autor, int codigo, int numero)
        : Material(titulo, autor, codigo), numero_(numero) {}

    void mostrarDetalles() const override {
        Material::mostrarDetalles();
        cout << "Número: " << numero_ << endl;
    }


};

int main() {
    // Crea objetos de diferentes tipos de materiales
    Libro libro("Nombre del libro", "Autor del libro", 1001, "Genero");
    Revista revista("Nombre de la Revista", "Autores de la Revista", 2002, 123); // codigo - numero de pagina

    // Crea un arreglo de punteros a Material
    Material* materiales[2];
    materiales[0] = &libro;
    materiales[1] = &revista;

    // Muestra detalles utilizando polimorfismo
    for (const auto& material : materiales) {
        material->mostrarDetalles();
        cout << "--------------------------" << endl;
    }
    
    return 0;
}