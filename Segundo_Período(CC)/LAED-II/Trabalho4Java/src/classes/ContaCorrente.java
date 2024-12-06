package classes;

public class ContaCorrente {
    private int numConta;
    private int cpfTitular;
    private double saldo;
    
    public ContaCorrente(int numConta, int cpfTitular, double saldo){
    this.numConta = numConta;
    this.cpfTitular = cpfTitular;
    this.saldo = saldo;
    }
    
    public int getNumConta(){
        return numConta;
    }
    
    public int getCpfTitular(){
        return cpfTitular;
    }
    
    public double getSaldo(){
        return saldo;
    }
    
    public void setSaldo(double saldo){
        this.saldo = saldo;
    }
       
      public void deposito(double valor) {
        saldo += valor; 
    }

    public void saque(double valor) {
        double porcentagem = 0.5 / 100; 
        double taxa = valor * porcentagem;
        
        saldo -= (valor + taxa); 
    }
    
    public void mostra(){
        System.out.println("Num da conta: " + numConta);
        System.out.println("CPF: " + cpfTitular);
        System.out.println("Saldo: " + saldo);
    }
    
    public void opcoes(){
        System.out.println("1- Depositar na conta;");
        System.out.println("2- Saque");
    }
}
