#include <iostream>
#include <string>
using namespace std;

// Estructura para representar los datos de cada municipio//
struct Municipio {
    std::string nombre;
    std::string alcalde;
    
    double presupuesto, ejecutado;
    
};

// Función para calcular el presupuesto asignado y ejecutado por estado//
double calcularPresupuesto(int numMunicipios, Municipio municipios[]) {
    double presupuestoAsignado = 0, presupuestoEjecutado = 0;
    
    for (int i = 0; i < numMunicipios; i++) {
        presupuestoAsignado += municipios[i].presupuesto;
        presupuestoEjecutado += municipios[i].ejecutado;
    }
    return presupuestoEjecutado / presupuestoAsignado * presupuestoAsignado; // Calcula el porcentaje de ejecución y multiplica por el presupuesto asignado para obtener el presupuesto ejecutado
}

int main() {
	int opcion;
    int numMunicipios; // Número de municipios del estado//
    
    std::cout << "Ingrese el numero de municipios del estado: ";
    std::cin >> numMunicipios;
    
    Municipio municipios[numMunicipios]; // Array para guardar los datos de los municipios del estado//
        for (int i = 0; i < numMunicipios; i++) { // Recorre el array de municipios para obtener sus datos y calcular el presupuesto ejecutado por estado//
    
        std::cout << "Ingrese el nombre del municipio " << i+1 << ": ";
        std::cin >> municipios[i].nombre;
        
        std::cout << "Ingrese el nombre del alcalde del municipio " << i+1 << ": "; // Pide al usuario que ingrese el nombre del alcalde del municipio actual//
        std::cin >> municipios[i].alcalde;
        
        std::cout << "Ingrese el presupuesto del municipio " << i+1 << ": ";
        std::cin >> municipios[i].presupuesto;
        
        std::cout << "Ingrese la cantidad ejecutada del municipio " << i+1 << ": ";
        std::cin >> municipios[i].ejecutado;
        
         do {
	 cout << "=============== MENU ===============";
	 cout << "Opcion 1. (Alcalde que incumplio con lo presupuestado)" << endl;
	 cout << "Opcion 2 (Alcalde remunerado por no haber ejecutado el presupuesto )" << endl;
	 cout << "3. Salir" << endl;
	 cout << "=====================================" << endl;
	 cout << "Selecciona una opcion:  ";
	 cin >> opcion;
	 switch (opcion) {
	 	case 1:
	 		cout << "Has seleccionado la opcion 1" << endl;
        
        if (municipios[i].ejecutado > municipios[i].presupuesto) { // Comprueba si se gasto más de lo presupuestado en este municipio//
        
            std::cout << "Se ha gastado más de lo presupuestado en el municipio " << municipios[i].nombre << ". El gasto fue: Bs." << municipios[i].ejecutado << endl;
            std::cout << "El alcalde " << municipios[i].alcalde << " va preso por gastar más de lo presupuestado.";
    
			
            }//fin del 1er IF
            break;
            
        case 2:
		   cout << "Has seleccionado la opcion 2" << endl;
		
		if (municipios[i].ejecutado < municipios[i].presupuesto) { // Comprueba si se gasto menos de lo presupuestado en este municipio//
		
		std::cout << "El municipio " << municipios[i].nombre << endl;
		std::cout << "Devuelve al alcalde " << municipios[i].alcalde << " el dinero restante del prespuesto por no haberlo ejecutado." << endl;
		
            }//fin del 2do IF
            break;
            
         case 3: 
		 std::cout << "Saliendo del programa..." << endl;
		 break;
		    
        }//fin de switch
        cout << endl;
        system ("pause");//Pausa interna del sistema
		system("cls"); 	
    } while (opcion !=3); //Hacer mientras la opcion sea distinta de (3).
    return 0;
}


            
}//fin de metodo main


        
