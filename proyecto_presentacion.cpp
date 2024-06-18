#include <iostream>
#include <string>

using namespace std;

// Clase base Material
class Material {
private:
  string titulo;
  string autor;
  int codigo;

public:
  Material(const string& titulo, const string& autor, int codigo)
      : titulo(titulo), autor(autor), codigo(codigo) {}

  virtual void mostrarDetalles() const {
    cout << "Título: " << titulo << ", Autor: " << autor << ", Código: " << codigo << endl;
  }
};

// Clase derivada Libro
class Libro : public Material {
private:
  string genero;
  int numPaginas;

public:
  Libro(const string& titulo, const string& autor, int codigo, const string& genero, int numPaginas)
      : Material(titulo, autor, codigo), genero(genero), numPaginas(numPaginas) {}

  void mostrarDetalles() const override {
    Material::mostrarDetalles();
    cout << "Género: " << genero << ", Número de páginas: " << numPaginas << endl;
  }
};

// Clase derivada Revista
class Revista : public Material {
private:
  string genero;
  int codigoRevista;
  int numeroRevista;

public:
  Revista(const string& titulo, const string& autor, int codigo, const string& genero, int codigoRevista, int numeroRevista)
      : Material(titulo, autor, codigo), genero(genero), codigoRevista(codigoRevista), numeroRevista(numeroRevista) {}

  void mostrarDetalles() const override {
    Material::mostrarDetalles();
    cout << "Género: " << genero << ", Código revista: " << codigoRevista << ", Número revista: " << numeroRevista << endl;
  }
};

// Clase derivada DVD
class DVD : public Material {
private:
  int duracion;
  string director;

public:
  DVD(const string& titulo, const string& autor, int codigo, int duracion, const string& director)
      : Material(titulo, autor, codigo), duracion(duracion), director(director) {}

  void mostrarDetalles() const override {
    Material::mostrarDetalles();
    cout << "Duración: " << duracion << " minutos" << ", Director: " << director << endl;
  }
};

// Función para mostrar el menú de detalles de materiales
void mostrarDetallesMateriales(Material* materiales[], int size) {
  cout << "\n1.1. Detalles de libros" << endl;
  cout << "1.2. Detalles de DVD's" << endl;
  cout << "1.3. Detalles de revistas" << endl;
  cout << "0. Volver al menú principal" << endl;
  cout << "Seleccione una opción: ";
  int opcion;
  cin >> opcion;

  if (opcion == 1) {
    materiales[0]->mostrarDetalles();
  } else if (opcion == 2) {
    materiales[2]->mostrarDetalles();
  } else if (opcion == 3) {
    materiales[1]->mostrarDetalles();
  } else if (opcion == 0) {
    return;
  } else {
    cout << "Opción no válida. Intente nuevamente." << endl;
  }

  mostrarDetallesMateriales(materiales, size);
}

void menuPrincipal(Material* materiales[], int size) {
  cout << "\nMenu Principal" << endl;
  cout << "1. Entrar al sistema de la biblioteca" << endl;
  cout << "2. Salir" << endl;
  cout << "Seleccione una opción: ";
  int opcion;
  cin >> opcion;

  if (opcion == 1) {
    mostrarDetallesMateriales(materiales, size);
  } else if (opcion == 2) {
    cout << "Saliendo del programa..." << endl;
    return;
  } else {
    cout << "Opción no válida. Intente nuevamente." << endl;
  }

  menuPrincipal(materiales, size);
}

int main() {
  // Crea objetos de diferentes tipos de materiales
  Libro libro("Nombre del libro", "Autor del libro", 1001, "Genero", 500);
  Revista revista("Nombre de la Revista", "Autores de la Revista", 2002, "Genero", 12345, 6);
  DVD dvd("Título del DVD", "Director del DVD", 3003, 120, "Genero del DVD");

  // Arreglo de punteros a objetos de tipo Material
  Material* materiales[3];
  materiales[0] = &libro;
  materiales[1] = &revista;
  materiales[2] = &dvd;

  menuPrincipal(materiales, 3);

  return 0;
}
