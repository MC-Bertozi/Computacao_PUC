package trabalho4java;

import classes.ContaCorrente;
import java.util.Locale;
import java.util.Scanner;

public class Trabalho4Java {
    public static void main(String[] args) {
        double n;
        
        Scanner scanner = new Scanner(System.in);
        scanner.useLocale(Locale.US);
        
        System.out.println("Digite o numero da conta:");
        int conta = scanner.nextInt();
        System.out.println("Digite o cpf: ");
        int cpf = scanner.nextInt();
        System.out.println("Digite o saldo atual: ");
        double saldo = scanner.nextDouble();
        ContaCorrente c1 = new ContaCorrente(conta, cpf, saldo);
                
        c1.mostra();
        c1.opcoes();
         
        System.out.println("O que deseja fazer? (Digite o numero da opcao escolhida):");
        int opcao = scanner.nextInt();    
        
       switch(opcao){
            case 1 -> {
               System.out.println("O quanto deseja depositar?:");
               n = scanner.nextDouble();
               c1.deposito(n);
                c1.mostra();
            }
            case 2 -> {
                System.out.println("O quanto deseja retirar no saque(taxa de 0.5%)?:");
                n = scanner.nextDouble();
                c1.saque(n);
                c1.mostra();
            }
        }
        
    }
    
}
