
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <Windows.h>
#include <conio.h>

float recaudaciones[4][7];
float gastos[4][7];
char diaDeSemana[][10]={"lunes","martes","miercoles","jueves","viernes","sabado","domingo"};
float TotalRecaudaciones[]={0,0,0,0};
float totalGastos[]={0,0,0,0};
float semanaMayorRec[2];
float gananciaDelMes = 0.0;
float gastosDelMes = 0.0;
float ingresosDelMes = 0.0;
int primerSemanaSinRecaudacion = -1;
int primerDiaSinRecaudacion = -1;

void colorPrintf(char color, char string[],char effect){

    /*
    funcion que se encarga de dar formato deseado a un texto
    recibe 3 valores: color del texto(la inicial del color en ingles: ejemplo: r -> RED),
    texto a mostrar, y efecto del texto(la inicial del efecto en ingles: ejemplo: u -> underline),
    */
    switch (color) {
        case 'r':
            switch(effect){
                case 's':
                    printf("\033[1;31;7m%s\033[0m",string);
                break;
                case 'b':
                    printf("\033[1;31;5m%s\033[0m",string);
                    break;
                case 'u':
                    printf("\033[1;31;4m%s\033[0m",string);
                    break;
                case 'd':
                    printf("\033[1;31;2m%s\033[0m",string);
                    break;
                default:
                    printf("\033[1;31m%s\033[0m",string);
                break;
            }
        break;
        case 'b':
            switch(effect){
                case 's':
                    printf("\033[1;34;7m%s\033[0m",string);
                break;
                case 'b':
                    printf("\033[1;34;5m%s\033[0m",string);
                    break;
                case 'u':
                    printf("\033[1;34;4m%s\033[0m",string);
                    break;
                case 'd':
                    printf("\033[1;34;2m%s\033[0m",string);
                    break;
                default:
                    printf("\033[1;34m%s\033[0m",string);
                break;
            }
        break;
        case 'c':
            switch(effect){
                case 's':
                    printf("\033[1;36;7m%s\033[0m",string);
                break;
                case 'b':
                    printf("\033[1;36;5m%s\033[0m",string);
                    break;
                case 'u':
                    printf("\033[1;36;4m%s\033[0m",string);
                    break;
                case 'd':
                    printf("\033[1;36;2m%s\033[0m",string);
                    break;
                default:
                    printf("\033[1;36m%s\033[0m",string);
                break;
            }
        break;
        case 'g':
            switch(effect){
                case 's':
                    printf("\033[1;32;7m%s\033[0m",string);
                break;
                case 'b':
                    printf("\033[1;32;5m%s\033[0m",string);
                    break;
                case 'u':
                    printf("\033[1;32;4m%s\033[0m",string);
                    break;
                case 'd':
                    printf("\033[1;32;2m%s\033[0m",string);
                    break;
                default:
                    printf("\033[1;32m%s\033[0m",string);
                break;
            }

        break;
        case 'y':
            switch(effect){
                case 's':
                    printf("\033[1;33;7m%s\033[0m",string);
                break;
                case 'b':
                    printf("\033[1;33;5m%s\033[0m",string);
                    break;
                case 'u':
                    printf("\033[1;33;4m%s\033[0m",string);
                    break;
                case 'd':
                    printf("\033[1;33;2m%s\033[0m",string);
                    break;
                default:
                    printf("\033[1;33m%s\033[0m",string);
                break;
            }
        break;
        case 'm':
            switch(effect){
                case 's':
                    printf("\033[1;35;7m%s\033[0m",string);
                break;
                case 'b':
                    printf("\033[1;35;5m%s\033[0m",string);
                    break;
                case 'u':
                    printf("\033[1;35;4m%s\033[0m",string);
                    break;
                case 'd':
                    printf("\033[1;35;2m%s\033[0m",string);
                    break;
                default:
                    printf("\033[1;35m%s\033[0m",string);
                break;
            }
        break;
        case 'w':
            switch(effect){
            case 's':
                printf("\033[0;7m%s\033[0m",string);
            break;
            case 'b':
                printf("\033[0;5m%s\033[0m",string);
            break;
            case 'u':
                printf("\033[0;4m%s\033[0m",string);
            break;
            case 'd':
                printf("\033[0;2m%s\033[0m",string);
            break;
            default:
                printf("\033[0;5m%s\033[0m",string);
            break;
            }
        break;
    }

}



void mostrarDatos(int semana, int dia){
     printf("💰Recaudacion: ");
     printf("%g\n",recaudaciones[semana-1][dia-1]);
     printf("📄💲gastos: ");
     printf("%g\n",gastos[semana-1][dia-1]);
}

void mostrarBarraSemanaDia(int semana,int dia){
    colorPrintf('c',"📅 semana",' ');
    printf(" %i | ",semana);
    colorPrintf('c',"dia",' ');
    printf(" %s \n",diaDeSemana[dia-1]);
}

void mostrarBarraSemana(int semana){
    colorPrintf('c',"📅 semana",' ');
    printf(" %i |",semana);
}

void mostrarBarraTitulo(int menu){
    system("cls");
    switch(menu){
        case 1:
            colorPrintf('c',"                                         .\n",'s');
            colorPrintf('c',"             📝Insertar Datos            .\n",'s');
            colorPrintf('c',"                                         .\n\n",'s');
        break;
        case 2:
            colorPrintf('y',"                                         .\n",'s');
            colorPrintf('y',"            📝Modificar datos            .\n",'s');
            colorPrintf('y',"                                         .\n\n",'s');
        break;
        case 3:
            colorPrintf('r',"                                         .\n",'s');
            colorPrintf('r',"            📝Eliminar datos             .\n",'s');
            colorPrintf('r',"                                         .\n\n",'s');
        break;
        case 4:
            colorPrintf('y',"                                          \n",'s');
            colorPrintf('y',"               📄💹Reporte                \n",'s');
            colorPrintf('y',"                                          \n\n",'s');
        break;
    }
}

bool insertarDatos(int semana, int dia){
    float recaudacion=0;
    float gasto=0;
    do{
        printf("\n💰Recaudacion: ");
        scanf("%f",&recaudacion);
        if(recaudacion<0)colorPrintf('r',"⚠️ No se permiten numeros negativos\n",' ');
    }while(recaudacion<0);
    recaudaciones[semana-1][dia-1] = recaudacion;
    do{
        printf("📄💲gastos: ");
        scanf("%f",&gasto);
        if(gasto<0)colorPrintf('r',"⚠️ No se permiten numeros negativos\n",' ');
    }while(gasto<0);
    gastos[semana-1][dia-1] = gasto;

    return true;
}

int obtenerNumeroValido(int desde, int hasta){
    int numero;
    do {
        scanf("%i",&numero);
        if (numero<desde || numero>hasta){
           colorPrintf('r',"⚠️ valor invalido, introduzca un valor entre: ",' ');
           printf("%i y %i\n",desde,hasta);
        }
    }
    while(numero<desde || numero >hasta);
    return numero;
}

bool borrarData(int semana, int dia){

    float dataRecaudacionDelDia = recaudaciones[semana-1][dia-1];
    float dataGastoDelDia = gastos[semana-1][dia-1];

    if(dataRecaudacionDelDia != -1 && dataGastoDelDia != -1){
        recaudaciones[semana-1][dia-1] = -1;
        gastos[semana-1][dia-1] = -1;
        return true;
    }else{
        return false;
    }

}

bool existeData(int semana, int dia){
    float recaudacion = recaudaciones[semana-1][dia-1];
    float gasto = gastos[semana-1][dia-1];
    if(recaudacion != -1 &&  gasto != -1)return true;
    else return false;

}

bool existeDataEnSemana(int semana){
    for(int i = 0 ; i<7 ; i++){
        if(existeData(semana,i+1))return true;
    }
    return false;
}

bool existeDataEnMes(){
    for(int i = 0 ; i < 4 ; i++){
        if(existeDataEnSemana(i+1))return true;
    }
    return false;

}

void limpiarData(){
    int i,a;
    for(i = 1 ; i<=4 ; i++){
        for(a = 1 ; a<=7 ; a++){
            borrarData(i,a);
        }
    }

}

void drawFlag(void){
    printf("\n");
    colorPrintf('b',"                  ",'s');
    colorPrintf('w',"     ",'s');
    colorPrintf('r',"                  \n",'s');
    colorPrintf('b',"                  ",'s');
    colorPrintf('w',"     ",'s');
    colorPrintf('r',"                  \n",'s');
    colorPrintf('b',"                  ",'s');
    colorPrintf('w',"     ",'s');
    colorPrintf('r',"                  \n",'s');
    colorPrintf('b',"                  ",'s');
    colorPrintf('w',"     ",'s');
    colorPrintf('r',"                  \n",'s');
    colorPrintf('w',"               Elca Comayor              \n",'s');
    colorPrintf('w',"                 2024-∞                  \n",'s');
    colorPrintf('r',"                  ",'s');
    colorPrintf('w',"     ",'s');
    colorPrintf('b',"                  \n",'s');
    colorPrintf('r',"                  ",'s');
    colorPrintf('w',"     ",'s');
    colorPrintf('b',"                  \n",'s');
    colorPrintf('r',"                  ",'s');
    colorPrintf('w',"     ",'s');
    colorPrintf('b',"                  \n",'s');
    colorPrintf('r',"                  ",'s');
    colorPrintf('w',"     ",'s');
    colorPrintf('b',"                  \n",'s');

}

void cleanScreen(void){
    /*se encarga de limpiar la pantalla de la terminal*/
    printf("\033[2J\033[H");
    //system("cls");
}


void insertarPrimerDiaSinRecaudacion(int semana,int dia){
    if(primerSemanaSinRecaudacion == -1 && primerDiaSinRecaudacion == -1){
        primerSemanaSinRecaudacion = semana+1;
        primerDiaSinRecaudacion = dia+1;
    }
}

void limpiarTotales(){
    gananciaDelMes = 0;
    gastosDelMes = 0;
    ingresosDelMes = 0;
    for(int i=0;i<4;i++){
        TotalRecaudaciones[i]=0;
        totalGastos[i]=0;
    }
}

void procesarDatos(){
    int i,a;
    limpiarTotales();
    for(i=0;i<4;i++){
        for(a=0;a<7;a++){
            if(recaudaciones[i][a] != -1 && gastos[i][a] != -1 ){
                if(recaudaciones[i][a] == 0){
                    insertarPrimerDiaSinRecaudacion(i,a);
                }
                TotalRecaudaciones[i]+= recaudaciones[i][a];
                totalGastos[i]+=gastos[i][a];
            }

        }
        if (i==0){
            semanaMayorRec[0]=1;
            semanaMayorRec[1]=TotalRecaudaciones[i];
        }
        if(TotalRecaudaciones[i] > semanaMayorRec[1]){
            semanaMayorRec[0]=i+1;
            semanaMayorRec[1]=TotalRecaudaciones[i];
        }

    }

    for(i=0;i<4;i++){
        ingresosDelMes += TotalRecaudaciones[i];
        gananciaDelMes += TotalRecaudaciones[i] - totalGastos[i];
        gastosDelMes += totalGastos[i];
    }

}

void mostrarSancion(){

    float resul = ingresosDelMes;
    colorPrintf('y',"  🚨Sancion aplicable\n",'s');
    if (resul < 5000 ) {
        colorPrintf('b',"  👷🏗️🚧Obras en la comunidad",' ');
    } else if (resul < 10000) {
        colorPrintf('c',"  🚔👮🏛️ 3 meses de prision 😧 ",' ');
    } else if (resul < 20000) {
         colorPrintf('y',"  🚔👮🏛️ 6 meses de prision 😨 ",'b');
    } else {
        colorPrintf('r',"  🚔👮🏛️ 1 año de prision 😱",'b');
    }
    printf("\n\n");
}


void renderReport(void){
    system("cls");
    int i,a;
    int indiceMejorDia;
    float mejorDia;
    mostrarBarraTitulo(4);

    colorPrintf('y',"🚫📅Primer dia sin recaudacion\n",' ');
    if(primerDiaSinRecaudacion != -1) printf("  dia %s de la semana %i\n\n",diaDeSemana[primerDiaSinRecaudacion-1],primerSemanaSinRecaudacion);
    else colorPrintf('g',"  💰Se recaudo todos los dias\n\n",'b');
    colorPrintf('c',"🥇📅Semana con mayor recaudacion\n",' ');
    printf("  Semana %g\n\n",semanaMayorRec[0]);
    colorPrintf('g',"📊💵Ganancias del mes\n",' ');
    printf("  %g \n\n",gananciaDelMes);
    mostrarSancion();

    for(i = 0 ; i<4 ; i++){
    mejorDia=0.0;
    indiceMejorDia=0;
    if(existeDataEnSemana(i+1)){
        colorPrintf('c',"\n   ",'s');
        mostrarBarraSemana(i+1);
        colorPrintf('c',"                         .\n\n",'s');
        colorPrintf('c',"💰Recaudaciones\n",' ');
        for(a = 0 ; a<7 ; a++){
            if(recaudaciones[i][a]>mejorDia){
                indiceMejorDia = a;
                mejorDia = recaudaciones[i][a];
            }
            printf("  %s :    ",diaDeSemana[a]);
            if(recaudaciones[i][a] == -1)colorPrintf('y',"Sin datos\n",'s');
            else printf("%g\n",recaudaciones[i][a]);

        }

        colorPrintf('c',"\n💰Total Recaudado\n",' ');
        printf("  %g\n",TotalRecaudaciones[i]);
        colorPrintf('g',"\n🥇Dia con mayor recaudacion\n",' ');
        printf("  %s\n",diaDeSemana[indiceMejorDia]);
        colorPrintf('m',"\n💵Ganancia de la semana\n",' ');
        printf("  %g\n\n\n",TotalRecaudaciones[i] - totalGastos[i]);

        }
    }

    colorPrintf('y',"Precione una tecla para volver al menu principal",'s');
    getch();
}

int contarLetras(char str[]){
    int i = 0;
    while(str[i]){
        i++;
    }
    return i;
}

void renderWidgetData(float valor,int widget){
    char dato[13];
    char newString[14];
    int longitud = 0;
    int i;
    sprintf(dato, " %g", valor);
    longitud = contarLetras(dato);

    i=0;
    while(dato[i]){
            newString[i] = dato[i];
            i++;
    }

    int leftRounds = 13 - longitud;
   for(i = 0; i<leftRounds; i++){
    newString[longitud]=' ';
    longitud++;
   }


   switch(widget){
    case 1:
        colorPrintf('g',newString,'s');
    break;
    case 2:
        colorPrintf('r',newString,'s');
    break;
    case 3:
        colorPrintf('c',newString,'s');
    break;
   }

}


void renderWidgets(bool haydata){
    printf("\n--💹RESUMEN-------------------------------\n\n");
    if(haydata)mostrarSancion();
    colorPrintf('g'," 💵Ingresos",' ');
    colorPrintf('r',"    💲Gastos",' ');
    colorPrintf('c',"      💰Ganancias\n",' ');
    printf(" ");
    colorPrintf('g',"             ",'s');
    printf(" ");
    colorPrintf('r',"             ",'s');
    printf(" ");
    colorPrintf('c',"             \n",'s');
    printf(" ");
    (haydata)?renderWidgetData(ingresosDelMes,1):colorPrintf('g'," Sin datos   ",'s');
    printf(" ");
    (haydata)?renderWidgetData(gastosDelMes,2):colorPrintf('r'," Sin datos   ",'s');
    printf(" ");
    (haydata)?renderWidgetData(gananciaDelMes,3):colorPrintf('c'," Sin datos   ",'s');
    printf("\n ");
    colorPrintf('g',"             ",'s');
    printf(" ");
    colorPrintf('r',"             ",'s');
    printf(" ");
    colorPrintf('c',"             \n",'s');
    printf("------------------------------------------\n\n");
}



void renderMainMenu(int selected){
    /*
    funcion que se encarga de pintar el menu principal del programa
    recive una opcion como entero, que luego la usa para pintar el menu
    con la seleccion correcta. no devuelve ningun valor.
    */
    bool haydata = existeDataEnMes();
    cleanScreen();
    drawFlag();
    renderWidgets(haydata);
    switch (selected){
        case 1:
            colorPrintf('c'," Introducir datos",' ');
            colorPrintf('c'," 👈\n",'b');
            if(haydata){
                printf("Modificar datos\n");
                printf("Eliminar datos\n");
                printf("Mostrar reporte\n");
            }else{
                colorPrintf('w',"Modificar datos\n",'d');
                colorPrintf('w',"Eliminar datos\n",'d');
                colorPrintf('w',"Mostrar reporte\n",'d');
            }
            printf("\nSALIR\n");
        break;
        case 2:
            printf("Introducir datos\n");
            colorPrintf('y'," Modificar datos",' ');
            colorPrintf('y'," 👈\n",'b');
            printf("Eliminar datos\n");
            printf("Mostrar reporte\n");
            printf("\nSALIR\n");
        break;
        case 3:
            printf("Introducir datos\n");
            printf("Modificar datos\n");
            colorPrintf('r'," Eliminar datos",' ');
            colorPrintf('r'," 👈\n",'b');
            printf("Mostrar reporte\n");
            printf("\nSALIR\n");
        break;
        case 4:
            printf("Introducir datos\n");
            printf("Modificar datos\n");
            printf("Eliminar datos\n");
            colorPrintf('g'," Mostrar reporte",' ');
            colorPrintf('g'," 👈\n",'b');
            printf("\nSALIR\n");
        break;
        case 5:
            printf("Introducir datos\n");
           if(haydata){
                printf("Modificar datos\n");
                printf("Eliminar datos\n");
                printf("Mostrar reporte\n");
            }else{
                colorPrintf('w',"Modificar datos\n",'d');
                colorPrintf('w',"Eliminar datos\n",'d');
                colorPrintf('w',"Mostrar reporte\n",'d');
            }
            colorPrintf('r',"\n SALIR",'s');
            colorPrintf('r'," 👈\n",'b');
        break;
    }
}

int mainMenuLogic(void){
    /*
    funcion que se encarga de la logica del menu principal.
    maneja los casos de seleccionar la opcion y devuelve como entero
    la opcion seleccionada.
    */
    int keyPressed=0;
    int option = 1;
    int keyUp = 72;
    int keyDown= 80;
    bool noExistenDatos ;
    do{
        noExistenDatos = !existeDataEnMes();
        if(keyPressed==keyUp && option>1){
            (noExistenDatos)?option=1:option--;

        }
        if(keyPressed==keyDown && option<5){
            (noExistenDatos)?option=5:option++;
        }

        renderMainMenu(option);
        keyPressed = getch();
    }while(keyPressed != 13 );
    return option;
}

void setUpTerminal(void){
    //funcion que se encarga de configurar la terminal para que todo se muestre correctamente.
    /*
      habilitando el codigo de escape ansi en la terminal.
      que solo viene por defecto en sistema unix(linux, macos), es necesario para
      poder renderizar colores y efectos en las letras que utilizamos a travez del codigo de escape ansi.
    */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | 0x0004);
    /*
    aqui estamos estableciendo el formato utf-8 en la terminal.
    necesario para renderizar los emojis.
    */
    SetConsoleOutputCP(65001);
}

int obtenerNumDia(char dia[]){
    int i,a;
    bool encontroDiaValido = false;
    for (a = 0; a<7 ; a++){
        i=0;
        while(diaDeSemana[a][i]){
            if(dia[i] != diaDeSemana[a][i]){
                encontroDiaValido = false;
                break;
            }else{
                encontroDiaValido= true;
            }
            i++;
        }
        if(encontroDiaValido)return a+1;
    }
    return 0;
}

int obtenerDiaValido(){
    char dia[9];
    int numDia;
    do{
        scanf("%s",dia);
        numDia = obtenerNumDia(dia);
        if(numDia==0)colorPrintf('r',"\n⚠️Inserte un dia valido\n",'b');
    }while(numDia==0);
    return numDia;
}

int insertWeekData(int numeroSemana){
    int option = 0;
    int numDia = 0;
    bool continuar,seInsertoData,noExisteData,noExisteDataEnDiaSiguiente;
    do{
        continuar = true;
        seInsertoData = false;
        printf("Escriba el dia : ");
        numDia = obtenerDiaValido();
        noExisteData = !existeData(numeroSemana,numDia);
        noExisteDataEnDiaSiguiente = !existeData(numeroSemana,numDia+1);
        if(noExisteData){
            do{
                mostrarBarraTitulo(1);
                mostrarBarraSemanaDia(numeroSemana,numDia);
                seInsertoData = insertarDatos(numeroSemana,numDia);
                if(numDia<7 && noExisteDataEnDiaSiguiente ){
                    colorPrintf('c',"\nENTER",'s');
                    printf(" : Continuar con el dia %s\n",diaDeSemana[numDia]);
                    colorPrintf('c',"Otra tecla",'s');
                    printf(" : Terminar\n\n");
                    if(getch() != 13)continuar=false;
                }
                numDia++;
            }while(numDia <= 7 && continuar && !existeData(numeroSemana,numDia));

        }
            mostrarBarraTitulo(1);
            mostrarBarraSemana(numeroSemana);
            if(!noExisteData){
                colorPrintf('r',"\n\n⚠️ Ya existen datos para este dia\n",'s');
                colorPrintf('y',"Para modificar los datos utilize la opcion\nmodificar datos en el menu principal\n",' ');
            }
            if(seInsertoData){
                procesarDatos();
                colorPrintf('g',"\n\n✅Datos insertados con exito\n",'s');
            }
            printf("\n1. Insertar otro dia\n");
            printf("2. seleccionar otra semana\n");
            printf("3. Menu Principal\n");
            option = obtenerNumeroValido(1,3);

    }while(option == 1);

    return option;

}

int obtenerNumeroSemanaValido(){
    int numeroSemana;
    do {
        scanf("%i",&numeroSemana);
        if (numeroSemana<1 || numeroSemana >4)colorPrintf('r',"⚠️ Numero de semana invalido, introduzca un valor entre 1 y 4\n",' ');
    }
    while(numeroSemana<1 || numeroSemana >4);
    return numeroSemana;
}

void insertDataOption(){

    int option;
    do {
        mostrarBarraTitulo(1);
        printf("📅");
        colorPrintf('y',"Inserte el Numero de la semana\n",'s');
        option = insertWeekData(obtenerNumeroSemanaValido());
    }while(option == 2);

}

int modificarDatos(int numeroSemana){
    int option=0;
    char select=' ';
    int numDia=0;
    bool seInsertoData;
    do{
        printf("Escriba el dia : ");
        numDia = obtenerDiaValido();
        seInsertoData = false;
        if(existeData(numeroSemana,numDia)){
            mostrarBarraTitulo(2);
            mostrarBarraSemanaDia(numeroSemana,numDia);
            printf("------------------------------------------\n");
            mostrarDatos(numeroSemana,numDia);
            printf("------------------------------------------\n\n");
            colorPrintf('y',"Desea modificar los datos de este dia?",'s');
            printf(" s/n \n");
            do{
                scanf(" %c",&select);
                if(select == 's') seInsertoData = insertarDatos(numeroSemana, numDia);
                else if (select != 'n') colorPrintf('r',"\n S para si, N para no\n",'b');
            }while(select != 's' && select != 'n');
        }
        mostrarBarraTitulo(2);
        mostrarBarraSemana(numeroSemana);
        if (!existeData(numeroSemana,numDia)){
            colorPrintf('r',"\n\n⚠️ No existen datos para este dia\n",'s');
            colorPrintf('y',"Para agregar datos utilize la opcion\nintroducir datos en el menu principal\n",' ');
        }
        if(seInsertoData){
            procesarDatos();
            colorPrintf('g',"\n\n✅Datos modificados con exito\n",'s');
        }
        printf("\n1. Modifcar otro dia\n");
        printf("2. Seleccionar otra semana\n");
        printf("3. Menu Principal\n");
        option = obtenerNumeroValido(1,3);

    }while(option == 1);
    return option;

}

void opcionModificarDatos(){
    int option;
    mostrarBarraTitulo(2);
    do {
        colorPrintf('y',"📅 Inserte el Numero de la semana\n",'s');
        option = modificarDatos(obtenerNumeroSemanaValido());
    }while(option == 2);

}

int EliminarDatosEnSemana(int numeroSemana){
    int option=0;
    char select=' ';
    int numDia=0;
    bool seEliminaronDatos,hayDatos;
    do{
        printf("Escriba el dia : ");
        numDia = obtenerDiaValido();
        seEliminaronDatos = false;
        hayDatos = existeData(numeroSemana,numDia);
        if(hayDatos){
            mostrarBarraTitulo(3);
            mostrarBarraSemanaDia(numeroSemana,numDia);
            printf("------------------------------------------\n");
            mostrarDatos(numeroSemana,numDia);
            printf("------------------------------------------\n\n");
            colorPrintf('r',"‼️ ELIMINAR los datos de este dia?",'s');
            printf(" s/n\n");
            do{
                scanf(" %c",&select);
                if(select == 's')seEliminaronDatos = borrarData(numeroSemana, numDia);
                else if (select != 'n')colorPrintf('r',"\n S para si, N para no\n",'b');
            }while(select != 's' && select != 'n');

        }
        mostrarBarraTitulo(3);
        mostrarBarraSemana(numeroSemana);
        if(!hayDatos)colorPrintf('r',"\n\n⚠️ No existen datos para este dia\n",'s');
        if(seEliminaronDatos){
                procesarDatos();
                colorPrintf('g',"\n\n✅Datos eliminados con exito\n",'s');
        }
        printf("\n1. seleccionar otro dia\n");
        printf("2. Seleccionar otra semana\n");
        printf("3. Menu Principal\n");
        option = obtenerNumeroValido(1,3);

    }while(option == 1);
    return option;
}

void opcionEliminarDatos(){
    int option;
    mostrarBarraTitulo(3);
    do {
        colorPrintf('y',"📅 Inserte el Numero de la semana\n",'s');
        option = EliminarDatosEnSemana(obtenerNumeroSemanaValido());
    }while(option == 2);
}

int main()
{
    setUpTerminal();
    limpiarData();
    bool ejecutar = true;
    while(ejecutar){
        switch (mainMenuLogic()){
            case 1:
                insertDataOption();
            break;
            case 2:
                opcionModificarDatos();
            break;
            case 3:
                opcionEliminarDatos();
            break;
            case 4:
                renderReport();
            break;
            case 5:
            ejecutar = false;
            break;
        }
    }
    return 0;
}
