import logo from './logo.svg';
import './App.css';
import PokemonCard from './components/PokemonCard'
function App() {
  return (
    <div className="App">
      <header className="App-header">
        <PokemonCard
        name="Pikachu"
        image= "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/25.png"
        type="Eletric"
        />
        <PokemonCard
        name="Bulbasaur"
        image= "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/1.png"
        type="Grass"
        />
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>
    </div>
  );
}

export default App;
