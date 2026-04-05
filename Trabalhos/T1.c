#include <stdio.h>

/* O COAF (Conselho de Controle de Atividades Financeiras), órgão
 do governo federal, te contratou para fazer um programa em C para extrair algumas
 informações das contas dos correntistas dos bancos do sistema financeiro nacional.
*/

// cu de trabalho vsf cacete merda cu cu cu

int main(void) {
    int banco, agencia, corr;
    double oper;

    double saldoAgencia = 0.0;
    double saldoBanco = 0.0;

    double maiorSaldo = -1e300;
    double segundoSaldo = -1e300;
    int mb1=0, ma1=0, mc1=0;
    int mb2=0, ma2=0, mc2=0;

    while (1) {
        if (scanf("%d", &banco) != 1) return 0;
        if (banco == -1) break;

        printf("banco %03d\n", banco);
        saldoBanco = 0.0;

        while (1) {
            if (scanf("%d", &agencia) != 1) return 0;
            if (agencia == -1) break;

            printf("agencia %d\n", agencia);
            saldoAgencia = 0.0;

            while (1) {
                if (scanf("%d", &corr) != 1) return 0;
                if (corr == -1) break;

                double saldoC = 0.0;

                while (1) {
                    if (scanf("%lf", &oper) != 1) return 0;
                    if (oper == 0.0) break;

                    if (oper > 30000.0 || oper < -30000.0) {
                        printf("operacao suspeita:  correntista %05d valor %.2lf\n",
                               corr, oper);
                    }

                    saldoC += oper;
                }

                printf("correntista %05d saldo %.2lf\n", corr, saldoC);
                saldoAgencia += saldoC;

                if (saldoC > maiorSaldo) {
                    segundoSaldo = maiorSaldo;
                    mb2 = mb1; ma2 = ma1; mc2 = mc1;

                    maiorSaldo = saldoC;
                    mb1 = banco; ma1 = agencia; mc1 = corr;
                } else if (saldoC > segundoSaldo) {
                    segundoSaldo = saldoC;
                    mb2 = banco; ma2 = agencia; mc2 = corr;
                }
            }

            printf("saldo agencia %.2lf\n", saldoAgencia);
            saldoBanco += saldoAgencia;
        }

        if (saldoBanco < 0.0) {
            printf("saldo banco deficitario: %.2lf\n", saldoBanco);
        }
    }

    if (segundoSaldo > -1e300) {
        printf("segundo maior correntista: banco %03d agencia %d correntista %05d saldo %.2lf\n",
               mb2, ma2, mc2, segundoSaldo);
    }
    if (maiorSaldo > -1e300) {
        printf("maior correntista: banco %03d agencia %d correntista %05d saldo %.2lf\n",
               mb1, ma1, mc1, maiorSaldo);
    }

    return 0;
}