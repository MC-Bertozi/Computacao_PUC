package classes;

public class ContaCorrente {
    private int numConta;
    private int cpfTitular;
    private int saldo;
    
    public ContaCorrente(int numConta, int cpfTitular, int saldo){
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
    
    public int getSaldo(){
        return saldo;
    }
    
    public void setSaldo(){
        this.saldo = saldo;
    }
    Scanner scan = new Scanner(System.in);
    sc.useLocale(Locale.US);
    
    public int Deposito{
    
    }
    
    public void mostra(){
        System.out.println("Num da conta: " + numConta);
        System.out.println("CPF: " + cpfTitular);
        System.out.println("Saldo: " + saldo);
    }
}
