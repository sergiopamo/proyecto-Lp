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

//El operador & lo utilizamos para declarar referencias a objetos de tipo "Material" 
//y para obtener las direcciones de memoria de estos objetos. Esto permite al arreglo materiales 
//almacenar punteros a objetos de diferentes clases derivadas de Material.

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

// Clase derivada DVD (sin cambios)
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

int main() {
  // Crea objetos de diferentes tipos de materiales con sus nuevos atributos
  Libro libro("Nombre del libro", "Autor del libro", 1001, "Genero", 500); //Se agrega el número de páginas al crear el objeto libro
  Revista revista("Nombre de la Revista", "Autores de la Revista", 2002, "Genero", 12345, 6); //Se agregan el código de revista y el número de revista al crear el objeto revista
  DVD dvd("Título del DVD", "Director del DVD", 3003, 120, "Genero del DVD"); //Se agrega el código del dvd, la duración y el director al crear el objeto dvd

  // Crea un arreglo llamado materiales, El tipo Material* indica que la variable materiales puede almacenar direcciones de memoria de objetos Material.
  Material* materiales[3];
  materiales[0] = &libro; //Asignación de punteros a objetos
  materiales[1] = &revista;
  materiales[2] = &dvd; //Arreglo de punteros a objetos de tipo Material y luego asigna punteros a objetos específicos de tipo Libro, Revista y DVD

  // Muestra detalles utilizando polimorfismo
  for (const auto& material : materiales) { //Este ciclo for recorre el arreglo materiales y llama al método mostrarDetalles() para cada objeto del arreglo. 
    material->mostrarDetalles(); //Esto permite mostrar los detalles de cada material (libro, revista o DVD) de manera uniforme.
    cout << "\n" << endl;
  }

  return 0;
}
