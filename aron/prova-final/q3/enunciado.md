% Sistemas Hardware-Software
% Igor Montagner

## Questão 3 (2,0)

Nesta questão iremos criar um programa **supervisor** que garante que um programa passado como argumento continuará rodando indefinidamente. Seu uso deverá ser o seguinte:

```
$> supervisor prog1
Iniciando prog1
(saída de prog1 aqui)
Erro: prog1 finalizou com o erro: Segmentation Fault
Reiniciando prog1
(saída de prog1 aqui)
Fim: prog1 terminou normalmente com saída 0
Reiniciando prog1
(saída de prog1 aqui)
Fim: prog1 terminado pelo sinal SIGKILL
```

Ou seja, o programa **supervisor** deverá

* executar o programa passado como argumento
    * se o programa passado não existir deverá mostrar a mensagem *Programa Inexistente* e finalizar
* esperar pelo término do programa e reiniciá-lo assim que isto ocorrer
* se o programa finalizar normalmente, deverá ser mostrado seu código de saída.
* se o programa finalizar com erro, deverá ser mostrada uma mensagem mostrando o erro encontrado
* se o programa for finalizado pelo sinal `SIGKILL` o **supervisor** deverá parar de reiniciar o programa e finalizar
* você **não** precisa se preocupar em passar argumentos para `prog1`.

Você deverá implementar seu programa no arquivo `supervisor.c`. Você pode usar os programas nesta pasta como teste. 

