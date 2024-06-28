#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Clase base Material
class Material {
protected:
    string titulo;
    string autor;
    int codigo;
public:
    Material(const string& titulo, const string& autor, int codigo)
        : titulo(titulo), autor(autor), codigo(codigo) {}

    virtual void mostrarDetalles() const = 0; // Método virtual puro
    virtual void guardar(ofstream& archivo) const = 0; // Método virtual puro para guardar
    virtual void cargar(ifstream& archivo) = 0; // Método virtual puro para cargar

    int getCodigo() const {
        return codigo;
    }
};

// Clase derivada Libro
class Libro : public Material {
protected:
    string genero;
    int numPaginas;
public:
    Libro() : Material("", "", 0), genero(""), numPaginas(0) {}
    Libro(const string& titulo, const string& autor, int codigo, const string& genero, int numPaginas)
        : Material(titulo, autor, codigo), genero(genero), numPaginas(numPaginas) {}

    void mostrarDetalles() const override {
        cout << "Título: " << titulo << ", Autor: " << autor << ", Código: " << codigo << endl;
        cout << "Género: " << genero << ", Número de páginas: " << numPaginas << endl;
    }

    void guardar(ofstream& archivo) const override {
        archivo << "LIBRO\n" << titulo << "\n" << autor << "\n" << codigo << "\n" << genero << "\n" << numPaginas << "\n";
    }

    void cargar(ifstream& archivo) override {
        getline(archivo, titulo);
        getline(archivo, autor);
        archivo >> codigo;
        archivo.ignore();
        getline(archivo, genero);
        archivo >> numPaginas;
        archivo.ignore();
    }
};

// Clase derivada DVD
class DVD : public Material {
protected:
    int duracion;
    string director;
public:
    DVD() : Material("", "", 0), duracion(0), director("") {}
    DVD(const string& titulo, const string& autor, int codigo, int duracion, const string& director)
        : Material(titulo, autor, codigo), duracion(duracion), director(director) {}

    void mostrarDetalles() const override {
        cout << "Título: " << titulo << ", Autor: " << autor << ", Código: " << codigo << endl;
        cout << "Duración: " << duracion << " minutos" << ", Director: " << director << endl;
    }

    void guardar(ofstream& archivo) const override {
        archivo << "DVD\n" << titulo << "\n" << autor << "\n" << codigo << "\n" << duracion << "\n" << director << "\n";
    }

    void cargar(ifstream& archivo) override {
        getline(archivo, titulo);
        getline(archivo, autor);
        archivo >> codigo;
        archivo.ignore();
        archivo >> duracion;
        archivo.ignore();
        getline(archivo, director);
    }
};

// Plantilla de clase Coleccion
template <typename T>
class Coleccion {
private:
    T** materiales;
    int cantidad;
    int capacidad;
    void expandirCapacidad() {
        capacidad *= 2;
        T** nuevoArreglo = new T*[capacidad];
        for (int i = 0; i < cantidad; ++i) {
            nuevoArreglo[i] = materiales[i];
        }
        delete[] materiales;
        materiales = nuevoArreglo;
    }
public:
    Coleccion() : cantidad(0), capacidad(10) {
        materiales = new T*[capacidad];
    }
    ~Coleccion() {
        for (int i = 0; i < cantidad; ++i) {
            delete materiales[i];
        }
        delete[] materiales;
    }
    void agregarMaterial(const T& material) {
        if (cantidad == capacidad) expandirCapacidad();
        materiales[cantidad++] = new T(material);
    }
    void eliminarMaterial(int codigo) {
        for (int i = 0; i < cantidad; ++i) {
            if (materiales[i]->getCodigo() == codigo) {
                delete materiales[i];
                for (int j = i; j < cantidad - 1; ++j) {
                    materiales[j] = materiales[j + 1];
                }
                --cantidad;
                materiales[cantidad] = nullptr;
                return;
            }
        }
        cout << "Material con código " << codigo << " no encontrado." << endl;
    }
    T* buscarMaterial(int codigo) {
        for (int i = 0; i < cantidad; ++i) {
            if (materiales[i]->getCodigo() == codigo) {
                return materiales[i];
            }
        }
        return nullptr;
    }
    void listarMateriales() const {
        for (int i = 0; i < cantidad; ++i) {
            materiales[i]->mostrarDetalles();
            cout << "\n";
        }
    }

    void guardarEnArchivo(const string& nombreArchivo) const {
        ofstream archivo(nombreArchivo);
        if (!archivo) {
            cerr << "No se pudo abrir el archivo para guardar." << endl;
            return;
        }
        archivo << cantidad << "\n";
        for (int i = 0; i < cantidad; ++i) {
            materiales[i]->guardar(archivo);
        }
    }

    void cargarDesdeArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo) {
            cerr << "No se pudo abrir el archivo para cargar." << endl;
            return;
        }
        int nuevaCantidad;
        archivo >> nuevaCantidad;
        archivo.ignore();

        for (int i = 0; i < cantidad; ++i) {
            delete materiales[i];
        }
        delete[] materiales;

        cantidad = 0;
        capacidad = nuevaCantidad > 10 ? nuevaCantidad : 10;
        materiales = new T*[capacidad];

        for (int i = 0; i < nuevaCantidad; ++i) {
            string tipo;
            getline(archivo, tipo);
            T* nuevoMaterial = new T();
            nuevoMaterial->cargar(archivo);
            agregarMaterial(*nuevoMaterial);
            delete nuevoMaterial;
        }
    }
};

int main() {
    int opcion;
    Coleccion<Libro> coleccionLibros;
    Coleccion<DVD> coleccionDVDs;

    coleccionLibros.cargarDesdeArchivo("libros.txt");
    coleccionDVDs.cargarDesdeArchivo("dvds.txt");

    do {
        cout << "Menú de la biblioteca:" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Agregar DVD" << endl;
        cout << "3. Listar libros" << endl;
        cout << "4. Listar DVDs" << endl;
        cout << "5. Buscar material" << endl;
        cout << "6. Eliminar material" << endl;
        cout << "7. Guardar colecciones" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string titulo, autor, genero;
                int codigo, numPaginas;
                cout << "Ingrese título del libro: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese autor del libro: ";
                getline(cin, autor);
                cout << "Ingrese código del libro: ";
                cin >> codigo;
                cout << "Ingrese género del libro: ";
                cin.ignore();
                getline(cin, genero);
                cout << "Ingrese número de páginas del libro: ";
                cin >> numPaginas;
                coleccionLibros.agregarMaterial(Libro(titulo, autor, codigo, genero, numPaginas));
                break;
            }
            case 2: {
                string titulo, director;
                int codigo, duracion;
                cout << "Ingrese título del DVD: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese director del DVD: ";
                getline(cin, director);
                cout << "Ingrese código del DVD: ";
                cin >> codigo;
                cout << "Ingrese duración del DVD (en minutos): ";
                cin >> duracion;
                coleccionDVDs.agregarMaterial(DVD(titulo, "Autor desconocido", codigo, duracion, director));
                break;
            }
            case 3:
                cout << "Lista de libros:" << endl;
                coleccionLibros.listarMateriales();
                break;
            case 4:
                cout << "Lista de DVDs:" << endl;
                coleccionDVDs.listarMateriales();
                break;
            case 5: {
                int codigoBuscar;
                cout << "Ingrese código del material a buscar: ";
                cin >> codigoBuscar;
                Libro* libroEncontrado = coleccionLibros.buscarMaterial(codigoBuscar);
                if (libroEncontrado) {
                    libroEncontrado->mostrarDetalles();
                } else {
                    DVD* dvdEncontrado = coleccionDVDs.buscarMaterial(codigoBuscar);
                    if (dvdEncontrado) {
                        dvdEncontrado->mostrarDetalles();
                    } else {
                        cout << "Material no encontrado." << endl;
                    }
                }
                break;
            }
            case 6: {
                int codigoEliminar;
                cout << "Ingrese código del material a eliminar: ";
                cin >> codigoEliminar;
                coleccionLibros.eliminarMaterial(codigoEliminar);
                coleccionDVDs.eliminarMaterial(codigoEliminar);
                break;
            }
            case 7:
                coleccionLibros.guardarEnArchivo("libros.txt");
                coleccionDVDs.guardarEnArchivo("dvds.txt");
                cout << "Colecciones guardadas correctamente." << endl;
                break;
            default:
                if (opcion != 0) {
                    cout << "Opción inválida. Intente nuevamente." << endl;
                }
        }
    } while (opcion != 0);

    return 0;
}
