#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct alumno {       
    char *nombres, *apellidoP, *apellidoM;
    int creditos, semestre;
    struct alumno *siguientePtr;
};
typedef struct alumno Alumno;
typedef Alumno* AlumnoPtr;

/*Firmas*/
void imprimirString(char *str);
void imprimirAlumno(AlumnoPtr alumno);
void imprimirLista(AlumnoPtr *cabecera);
AlumnoPtr crearNodo(char *nombres, char *apellidoP, char *apellidoM, int cre, int sem);
void insertarNodoOrdenadoCreditos(AlumnoPtr *cabecera, AlumnoPtr nuevo);

int main()
{
    AlumnoPtr cabecera = NULL;

    insertarNodoOrdenadoCreditos(&cabecera, crearNodo("Pedro", "Hernandez", "Cuevas", 3, 82));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo("Jorge", "Uk", "Novelo", 1, 5));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo("Jose Luis", "Lara", "Rubio", 5, 87));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo("Francisco", "Rodriguez", "Canto", 4, 12));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo("Juan", "Zurita", "Campos", 7, 41));

    imprimirLista(&cabecera);

    getchar();
    return 0;
}

void imprimirString(char *str){
    for(int i = 0; i < strlen(str); i++){
        printf("%c", str[i]);
    }
}

void imprimirAlumno(AlumnoPtr alumno){
    printf("Nombre: ");
    imprimirString(alumno->apellidoP);
    printf(" ");
    imprimirString(alumno->apellidoM);
    printf(", ");
    imprimirString(alumno->nombres);

    printf("  |  Semestre: %d  | Creditos Aprobados: %d\n", alumno->semestre, alumno->creditos);
}

void imprimirLista(AlumnoPtr *cabecera){
    AlumnoPtr actual;
    actual = *cabecera;

    while (actual != NULL)
    {
        imprimirAlumno(actual);
        actual = actual->siguientePtr;
    }
    
}

AlumnoPtr crearNodo(char *nombres, char *apellidoP, char *apellidoM, int cre, int sem){
    AlumnoPtr nuevoAlumno;

    nuevoAlumno = (AlumnoPtr)malloc(sizeof(Alumno));

    printf("Se ha creado un struct alumno en la direccion: %p\n", nuevoAlumno);

    nuevoAlumno->siguientePtr = NULL;

    nuevoAlumno->apellidoP = apellidoP;
    nuevoAlumno->apellidoM = apellidoM;
    nuevoAlumno->nombres = nombres;
    nuevoAlumno->semestre = cre;
    nuevoAlumno->creditos = sem;

    return nuevoAlumno;
}


void insertarNodoOrdenadoCreditos(AlumnoPtr *cabecera, AlumnoPtr nuevo){
    AlumnoPtr anterior = NULL, actual;

    if (*cabecera == NULL)
    {
        printf("Se ha insertado un nodo en la lista en la dirección: %p\n\n", nuevo);

        *cabecera = nuevo;
        return;
    }
    actual = *cabecera;

    while (actual != NULL)
    {
        if(actual->creditos < nuevo->creditos){
            break;
        }
      
        anterior = actual;
        actual = actual->siguientePtr;
        
    }

    if(anterior == NULL){
        nuevo->siguientePtr = actual;
        *cabecera = nuevo;       
    }else{
        anterior->siguientePtr = nuevo;
        nuevo->siguientePtr = actual;
    }

    printf("Se ha insertado un nodo en la dirección: %p\n\n", nuevo);
}