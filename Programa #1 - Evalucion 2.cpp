//Programa Bloquera

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //Inicializamos las variables
    int n = 0;
    int codigo, arcilla = 0, cemento = 0;
    float precio_arcilla = 230, precio_cemento = 350;
    float monto = 0, descuento = 0, monto_total = 0;
    int codigo_max = 0;
    float monto_max = 0;
    int total_arcilla = 0, total_cemento = 0, total_bloques = 0;

    //Pedimos el número de ventas a procesar
    cout << "Ingrese el numero de ventas a procesar: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        //Pedimos los datos de la venta
        cout << "Datos de la venta #" << i << "\n";
        cout << "Codigo del cliente(C.I): ";
        cin >> codigo;
        cout << "Cantidad de bloques de arcilla comprados: ";
        cin >> arcilla;
        cout << "Cantidad de bloques de cemento comprados: ";
        cin >> cemento;

        //Calculamos el monto total sin descuento
        monto = arcilla * precio_arcilla + cemento * precio_cemento;

        //Calculamos el descuento
        if (monto > 0) {
            if (descuento >= 3) {
                descuento = monto * 0.03;
            } else {
                descuento = 0;
            }
        } else {
            descuento = 0;
        }

        //Calculamos el monto total con descuento
        monto_total = monto - descuento;

        //Calculamos el total de bloques vendidos
        total_arcilla += arcilla;
        total_cemento += cemento;
        total_bloques += arcilla + cemento;

        //Actualizamos el código y monto máximo
        if (monto_total > monto_max) {
            monto_max = monto_total;
            codigo_max = codigo;
        }

        //Imprimimos los datos de la venta
        cout << "\n";
        cout << "Venta procesada:\n";
        cout << "Cliente: " << codigo << "\n";
        cout << "Arcilla: " << arcilla << " bloques.\n";
        cout << "Cemento: " << cemento << " bloques.\n";
        cout << "Monto sin descuento: Bs. " << fixed << setprecision(2) << monto << "\n";
        cout << "Descuento: Bs. " << fixed << setprecision(2) << descuento << "\n";
        cout << "Monto total con descuento: Bs. " << fixed << setprecision(2) << monto_total << "\n\n";
    }

    //Calculamos porcentajes
    float porcentaje_arcilla = (float) total_arcilla / total_bloques * 100;
    float porcentaje_cemento = (float) total_cemento / total_bloques * 100;

    //Imprimimos los resultados finales
    cout << "Resultados:\n";
    cout << "Cliente con mayor monto total de compras: " << codigo_max << " (Bs. " << fixed << setprecision(2) << monto_max << ")\n";
    cout << "Porcentaje de bloques de arcilla vendidos: " << fixed << setprecision(2) << porcentaje_arcilla << "%\n";
    cout << "Porcentaje de bloques de cemento vendidos: " << fixed << setprecision(2) << porcentaje_cemento << "%\n";

    return 0;

}
