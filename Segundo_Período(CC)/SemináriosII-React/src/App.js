import logo from './Conhecimento.webp';
import './App.css';
import MeuComponente from './MeuComponente';
import MeusHobbies from './MeusHobbies';
import NovoCoponente from './NovoComponente';

function App() {
  const nome = "Pudim"
  const hob1 = "Ler"
  const hob2 = "Jogar RPG (ex: Ordem Paranormal)"
  const hob3 = "Jogar jogos digitais"
  const gosto = "COISAS QUE NAO GOSTO:"
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
        Saber tudo é perder tudo.
        </p>
        <a
          className="App-link"
          /*href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"*/
          href="https://ordemparanormal.fandom.com/wiki/Ordem_Paranormal_Wiki"
          target="_blank"
          rel="noopener noreferrer"
        >
          Ordem Paranormal RPG Wiki
        </a>
        <MeuComponente Apelido={nome}/>
        <MeusHobbies hobbie1={hob1} hobbie2={hob2} hobbie3={hob3}/>
        <NovoCoponente Gostos={gosto}/>
      </header>
    </div>
  );
}

export default App;