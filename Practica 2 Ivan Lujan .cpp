//Practica 2 Ivan Lujan 23310158 
//Programacion Orientada a objetos
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Usuario{
    protected: //Atributos que tendra la clase usuario
        string nombre;
        string telefono;
        int edad;
        string pwd;

    public: //Metodos que usa la clase
        Usuario(const string& nombre, const string& telefono, int edad, const string& pwd)
            : nombre(nombre), telefono(telefono), edad(edad), pwd(pwd) {};

        virtual void mostrarInfo() const{
            cout<<"Nombre: "<<nombre<<"\nTelefono: "<<telefono<<"\nEdad: "<<edad<<endl;
        }
        bool validarPassword(const string& inputPwd) const{
            return inputPwd == pwd;
        }
        virtual void cambiarPassword(const string& nuevaPwd){
            pwd = nuevaPwd;
        }
        string getNombre() const{
            return nombre;
        }
};
//La clase cliente que hereda de la clase padre "Usuario"
class Cliente : public Usuario{
    public:
        Cliente(const string& nombre, const string& telefono, int edad, const string& pwd)//Constructor
            : Usuario(nombre, telefono, edad, pwd) {};
//Metodos que el cliente usara
            void comprar() const {
                cout<<getNombre()<<" ha realizado una compra."<<endl;
            }
            void vender() const{
                cout<<getNombre()<<" ha realizado una venta."<<endl;
            }
            void devolucion() const{
                cout<<getNombre()<<" ha realizado una devolucion."<<endl;
            }
            void cambiarPassword(const string& nuevaPwd) override{
                pwd = nuevaPwd;
                cout<<"Password cambiada exitosamente para el cliente "<<nombre<<endl;
            }
};
//La clase vendedor que hereda de la clase padre "usuario"
class Vendedor : public Usuario{
    public:
        Vendedor(const string& nombre, const string& telefono, int edad, const string& pwd)
            : Usuario(nombre, telefono, edad, pwd){}
//Metodos que el vendedor usara
            void ventas()const {
            cout<<getNombre()<<" esta revisando sus ventas."<<endl;
            }
            void actualizarInfo() const{
            cout<<getNombre()<<" esta actualizando su informacion."<<endl;
            }
            void cambiarPassword(const string& nuevaPwd) override{
                pwd =nuevaPwd;
                cout<<"Password cambiada exitosamente para el vendedor "<<nombre<<endl;
            }
};
int main(){
//ejemplo de uso de la practica
    Cliente cliente("Ivan", "3317649526", 20, "password_cliente");
    Vendedor vendedor("Maria", "3311263811", 30, "password_vendedor");

//Mostrar informacion de usuario
    cliente.mostrarInfo();
    vendedor.mostrarInfo();

//Cambiar Password
    cliente.cambiarPassword("nueva_password_cliente");
    vendedor.cambiarPassword("nueva_password_vendedor");

//Validar password
    string inputPwd;
    cout<<"Ingrese la Password para el cliente"<< cliente.getNombre() <<": ";
    cin>>inputPwd;

        if (cliente.validarPassword(inputPwd)){
         cout<<"Password valida. Acceso concedido."<<endl;

            //Acciones del cliente
            cliente.comprar();
            cliente.vender();
            cliente.devolucion();
        } else{
        cout<<"Password incorrecta. Acceso denegado."<<endl;
    }

//Validar password
    cout<<"Ingrese la Password para el vendedor "<<vendedor.getNombre()<<":";
    cin>>inputPwd;

        if(vendedor.validarPassword(inputPwd)){
            cout<<"Password valida. Acceso concedido."<<endl;
    
        //Acciones del vendedor
        vendedor.ventas();
        vendedor.actualizarInfo();
    } else{
        cout<<"Password incorrecta. Acceso denegado.";
    }

    return 0;
}