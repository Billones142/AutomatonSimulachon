#include <stdio.h>
#include <string.h>

enum estados
{
  q0, // si es 1 pasa a estado q1 y si es 0 pasa a estado q2
  q1, // acepta los 0 y pasa a estado q3 o sino pasa a estado q3
  q2, // acepta los 1 y pasa a estado q2 o sino pasa a estado q3
  q3, // estado que sirve solo para ser rechazado (me recuerda a mi)
};

int estado = q0;
int valueIndex = 0;
void funcionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo(
    char *nuevoValorParaLaFuncionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo,
    int nuevoEstadoParaLaFuncionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo,
    char userValueParaLaFuncionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo[])
{
  if (nuevoValorParaLaFuncionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo != NULL)
  {
    userValueParaLaFuncionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo[valueIndex] = *nuevoValorParaLaFuncionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo;
  }

  estado = nuevoEstadoParaLaFuncionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo;
  valueIndex++;
};

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Error: Please provide an input string\n");
    return 1;
  }

  char *value = argv[1]; // the first string that is piped to the program

  // Calculate the length of the string
  size_t stringLength = strlen(value);

  // Function to get the actual value at the current index
  char actualValue()
  {
    if (valueIndex >= stringLength)
    {
      return '\0';
    }
    return value[valueIndex];
  };

  while (valueIndex < stringLength)
  {
    switch (estado)
    {
    case q0:
      switch (actualValue())
      {
      case '0':
        funcionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo(NULL, q2, value);
        break;
      case '1':
        funcionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo(NULL, q1, value);
        break;
      }
      break;
    case q1:
      switch (actualValue())
      {
      case '0':
        funcionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo(NULL, q2, value);
        break;
      case '1':
        funcionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo(NULL, q3, value);
        break;
      }
      break;
    case q2:
      switch (actualValue())
      {
      case '1':
        funcionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo(NULL, q1, value);
        break;
      case '0':
        funcionGeneralizadaParaUsarEnTodosLosEstadosDeEsteAutomataParaSimplificarElProcesoDeEscrituraDelCodigo(NULL, q3, value);
        break;
      }
      break;
    case q3:
      // does nothing
      valueIndex = stringLength + 1;
      break;
    default:
      break;
    }
  }

  printf("se termino con estado q%d ", estado);

  switch (estado)
  {
  case q1:
    printf("(aceptacion)");
    return 1;
    break;

  case q2:
    printf("(aceptacion)");
    return 2;
    break;

  default:
    printf("(no aceptacion)");
    return 0;
    break;
  }
}