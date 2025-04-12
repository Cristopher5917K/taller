    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    #include <ctype.h>

    void cleanBuff()
    {
        while (getchar() != '\n');
            
    }

    int main()
    {
        int id, stock, cantidad, opcion;
        float precio, total_ganancias = 0;
        char nombre[90];

        do
        {
            printf("\nIngrese el ID del producto: ");
            if (scanf("%d", &id) != 1 || id <= 0)
            {
                printf("\nID inválido ingrese solo números enteros positivos.\n");
                cleanBuff();
                continue;
            }
            break;
        } while (1);

        printf("\nIngrese el nombre del producto: ");
        cleanBuff();
        fgets(nombre, 90, stdin);
        

        do
        {
            printf("\nIngrese la cantidad inicial en stock: ");
            if (scanf("%d", &stock) != 1 || stock <= 0)
            {
                printf("\nCantidad invalida, ingrese solo numeros enteros positivos \n");
                cleanBuff();
                continue;
            }
            break;
        } while (1);

        do
        {
            printf("\nIngrese el precio unitario del producto: ");
            if (scanf("%f", &precio) != 1 || precio <= 0)
            {
                printf("\nPrecio invalido, ingrese solo numeros enteros positivos");
                cleanBuff();
                continue;
            }
            break;
        } while (1);

        do
        {
            printf("\nMenú de Opciones:\n");
            printf("1. Vender producto\n");
            printf("2. Reabastecer producto\n");
            printf("3. Mostrar información del producto\n");
            printf("4. Mostrar total de ganancias\n");
            printf("5. Salir\n");
            printf("Seleccione una opción: ");

            if (scanf("%d", &opcion)!=1)
            {
                printf("El valor que usted ingreso no esta disponible porfavor intente de nuevo");
                cleanBuff();
                continue;
            }
            
            

            switch (opcion)
            {
            case 1:
                do
                {
                    printf("Ingrese la cantidad a vender: ");

                    if (scanf("%d", &cantidad) != 1 || cantidad <= 0)
                    {
                        printf("\nCantidad inválida, ingrese solo números enteros positivos.\n");
                        cleanBuff(); 
                        continue;
                    }

                    if (cantidad > stock)
                    {
                        printf("No hay suficiente stock, ingrese una cantidad válida.\n");
                        continue; 
                    }

                
                    break;

                } while (1); 

        
                stock -= cantidad;
                total_ganancias += cantidad * precio;
                printf("Venta realizada con éxito. Stock restante: %d\n", stock);

                break;

            case 2:

                do
                {
                    printf("Ingrese la cantidad a agregar al stock: ");
                    if (scanf("%d", &cantidad) != 1 || cantidad <= 0)
                    {
                        printf("\nCantidad invalida, ingrese solo numeros enteros positivos");
                        cleanBuff();
                        continue;
                    }
                    stock+=cantidad;
                    printf("La cantidad de stock se actualizo total:%d", stock);
                    break;
                } while (1);

                break;

            case 3:
                printf("\nInformación del producto:\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 4:
                printf("Total de ganancias: $%.2f\n", total_ganancias);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
            }
        } while (opcion != 5);

        return 0;
    }