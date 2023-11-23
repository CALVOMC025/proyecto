#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDIANTES 100
#define MAX_PROFESORES 50
#define MAX_AULAS 20

struct Estudiante {
    char nombre[50];
    char apellidos[50];
    int codigo;
    int semestre;
    float notaFinal;
};

struct Profesor {
    char nombre[50];
    char apellidos[50];
    int codigo;
    char especialidad[50];
};

struct Aula {
    int numero;
    char edificio[20];
    int capacidad;
};

void agregarEstudiante(struct Estudiante *estudiantes, int *numEstudiantes) {
    struct Estudiante nuevoEstudiante;

    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nuevoEstudiante.nombre);

    printf("Ingrese los apellidos del estudiante: ");
    scanf("%s", nuevoEstudiante.apellidos);

    printf("Ingrese el código del estudiante: ");
    scanf("%d", &nuevoEstudiante.codigo);

    for (int i = 0; i < *numEstudiantes; i++) {
        if (estudiantes[i].codigo == nuevoEstudiante.codigo) {
            printf("¡Error! El código ya existe. No se puede agregar al estudiante.\n");
            return 0;
        }
    }

    printf("Ingrese el número de semestre del estudiante: ");
    scanf("%d", &nuevoEstudiante.semestre);

    printf("Ingrese la nota final del estudiante: ");
    scanf("%f", &nuevoEstudiante.notaFinal);

    estudiantes[*numEstudiantes] = nuevoEstudiante;
    (*numEstudiantes)++;

    printf("Estudiante agregado con éxito.\n");
}

void buscarEstudiante(const struct Estudiante *estudiantes, int numEstudiantes) {
    int codigoBuscar;
    printf("Ingrese el código del estudiante a buscar: ");
    scanf("%d", &codigoBuscar);

    int encontrado = 0;

    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantes[i].codigo == codigoBuscar) {
            printf("Datos del estudiante:\n");
            printf("Nombre: %s %s\n", estudiantes[i].nombre, estudiantes[i].apellidos);
            printf("Código: %d\n", estudiantes[i].codigo);
            printf("Semestre: %d\n", estudiantes[i].semestre);
            printf("Nota Final: %.2f\n", estudiantes[i].notaFinal);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Estudiante no encontrado.\n");
    }
}

void eliminarEstudiante(struct Estudiante *estudiantes, int *numEstudiantes) {
    int codigoEliminar;
    printf("Ingrese el código del estudiante a eliminar: ");
    scanf("%d", &codigoEliminar);

    for (int i = 0; i < *numEstudiantes; i++) {
        if (estudiantes[i].codigo == codigoEliminar) {
            printf("Datos del estudiante a eliminar:\n");
            printf("Nombre: %s %s\n", estudiantes[i].nombre, estudiantes[i].apellidos);
            printf("Código: %d\n", estudiantes[i].codigo);
            printf("Semestre: %d\n", estudiantes[i].semestre);
            printf("Nota Final: %.2f\n", estudiantes[i].notaFinal);

            char confirmacion;
            printf("¿Está seguro de que desea eliminar a este estudiante? (S/N): ");
            scanf(" %c", &confirmacion);

            if (confirmacion == 'S' || confirmacion == 's') {
                for (int j = i; j < *numEstudiantes - 1; j++) {
                    estudiantes[j] = estudiantes[j + 1];
                }
                (*numEstudiantes)--;
                printf("Estudiante eliminado con éxito.\n");
                return;
            } else {
                printf("Eliminación cancelada.\n");
                return;
            }
        }
    }

    printf("Estudiante no encontrado.\n");
}

void agregarProfesor(struct Profesor *profesores, int *numProfesores) {
    struct Profesor nuevoProfesor;

    printf("Ingrese el nombre del profesor: ");
    scanf("%s", nuevoProfesor.nombre);

    printf("Ingrese los apellidos del profesor: ");
    scanf("%s", nuevoProfesor.apellidos);

    printf("Ingrese el código del profesor: ");
    scanf("%d", &nuevoProfesor.codigo);

    for (int i = 0; i < *numProfesores; i++) {
        if (profesores[i].codigo == nuevoProfesor.codigo) {
            printf("¡Error! El código ya existe. No se puede agregar al profesor.\n");
            return;
        }
    }

    printf("Ingrese la especialidad del profesor: ");
    scanf("%s", nuevoProfesor.especialidad);

    profesores[*numProfesores] = nuevoProfesor;
    (*numProfesores)++;

    printf("Profesor agregado con éxito.\n");
}

void buscarProfesor(const struct Profesor *profesores, int numProfesores) {
    int codigoBuscar;
    printf("Ingrese el código del profesor a buscar: ");
    scanf("%d", &codigoBuscar);

    int encontrado = 0;

    for (int i = 0; i < numProfesores; i++) {
        if (profesores[i].codigo == codigoBuscar) {
            printf("Datos del profesor:\n");
            printf("Nombre: %s %s\n", profesores[i].nombre, profesores[i].apellidos);
            printf("Código: %d\n", profesores[i].codigo);
            printf("Especialidad: %s\n", profesores[i].especialidad);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Profesor no encontrado.\n");
    }
}

void eliminarProfesor(struct Profesor *profesores, int *numProfesores) {
    int codigoEliminar;
    printf("Ingrese el código del profesor a eliminar: ");
    scanf("%d", &codigoEliminar);

    for (int i = 0; i < *numProfesores; i++) {
        if (profesores[i].codigo == codigoEliminar) {
            printf("Datos del profesor a eliminar:\n");
            printf("Nombre: %s %s\n", profesores[i].nombre, profesores[i].apellidos);
            printf("Código: %d\n", profesores[i].codigo);
            printf("Especialidad: %s\n", profesores[i].especialidad);

            char confirmacion;
            printf("¿Está seguro de que desea eliminar a este profesor? (S/N): ");
            scanf(" %c", &confirmacion);

            if (confirmacion == 'S' || confirmacion == 's') {
                for (int j = i; j < *numProfesores - 1; j++) {
                    profesores[j] = profesores[j + 1];
                }
                (*numProfesores)--;
                printf("Profesor eliminado con éxito.\n");
                return;
            } else {
                printf("Eliminación cancelada.\n");
                return;
            }
        }
    }

    printf("Profesor no encontrado.\n");
}

void agregarAula(struct Aula *aulas, int *numAulas) {
    struct Aula nuevaAula;

    printf("Ingrese el número del aula: ");
    scanf("%d", &nuevaAula.numero);

    printf("Ingrese el edificio del aula: ");
    scanf("%s", nuevaAula.edificio);

    printf("Ingrese la capacidad del aula: ");
    scanf("%d", &nuevaAula.capacidad);

    aulas[*numAulas] = nuevaAula;
    (*numAulas)++;

    printf("Aula agregada con éxito.\n");
}

void buscarAula(const struct Aula *aulas, int numAulas) {
    int numeroBuscar;
    printf("Ingrese el número del aula a buscar: ");
    scanf("%d", &numeroBuscar);

    int encontrado = 0;

    for (int i = 0; i < numAulas; i++) {
        if (aulas[i].numero == numeroBuscar) {
            printf("Datos del aula:\n");
            printf("Número: %d\n", aulas[i].numero);
            printf("Edificio: %s\n", aulas[i].edificio);
            printf("Capacidad: %d\n", aulas[i].capacidad);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Aula no encontrada.\n");
    }
}

void eliminarAula(struct Aula *aulas, int *numAulas) {
    int numeroEliminar;
    printf("Ingrese el número del aula a eliminar: ");
    scanf("%d", &numeroEliminar);

    for (int i = 0; i < *numAulas; i++) {
        if (aulas[i].numero == numeroEliminar) {
            printf("Datos del aula a eliminar:\n");
            printf("Número: %d\n", aulas[i].numero);
            printf("Edificio: %s\n", aulas[i].edificio);
            printf("Capacidad: %d\n", aulas[i].capacidad);

            char confirmacion;
            printf("¿Está seguro de que desea eliminar esta aula? (S/N): ");
            scanf(" %c", &confirmacion);

            if (confirmacion == 'S' || confirmacion == 's') {
                for (int j = i; j < *numAulas - 1; j++) {
                    aulas[j] = aulas[j + 1];
                }
                (*numAulas)--;
                printf("Aula eliminada con éxito.\n");
                return;
            } else {
                printf("Eliminación cancelada.\n");
                return;
            }
        }
    }

    printf("Aula no encontrada.\n");
}

int main() {
    struct Estudiante estudiantes[MAX_ESTUDIANTES];
    struct Profesor profesores[MAX_PROFESORES];
    struct Aula aulas[MAX_AULAS];

    int numEstudiantes = 0;
    int numProfesores = 0;
    int numAulas = 0;
    int opcion;

    do {
        printf("\nMenú:\n");
        printf("1. Agregar estudiante\n");
        printf("2. Buscar estudiante\n");
        printf("3. Eliminar estudiante\n");
        printf("4. Agregar profesor\n");
        printf("5. Buscar profesor\n");
        printf("6. Eliminar profesor\n");
        printf("7. Agregar aula\n");
        printf("8. Buscar aula\n");
        printf("9. Eliminar aula\n");
        printf("10. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarEstudiante(estudiantes, &numEstudiantes);
                break;
            case 2:
                buscarEstudiante(estudiantes, numEstudiantes);
                break;
            case 3:
                eliminarEstudiante(estudiantes, &numEstudiantes);
                break;
            case 4:
                agregarProfesor(profesores, &numProfesores);
                break;
            case 5:
                buscarProfesor(profesores, numProfesores);
                break;
            case 6:
                eliminarProfesor(profesores, &numProfesores);
                break;
            case 7:
                agregarAula(aulas, &numAulas);
                break;
            case 8:
                buscarAula(aulas, numAulas);
                break;
            case 9:
                eliminarAula(aulas, &numAulas);
                break;
            case 10:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 10);

    return 0;
}
