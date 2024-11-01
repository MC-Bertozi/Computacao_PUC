import { useEffect, useState } from "react";
import PokemonCard from "./PokemonCard";

function PokemonList() {
  const [selectedPokemon, setSelectedPokemon] = useState(null)
  const handleCardClick = (pokemon) => {
    setSelectedPokemon(pokemon)
  }
// https://github.com/xxmgkxx/pokedex2014

  const [pokemonList, setPokemonList] = useState([])

  useEffect(() => {
    fetch('https://pokeapi.co/api/v2/pokemon?limit=151')
    .then((response) => response.json())
    .then((data) => { setPokemonList (data.results)})
    .catch((error) => console.error("Erro ao buscar os dados", error));
  }, [])
  return(
    <div>
      {selectedPokemon ? (
        <div>
          <h2>Detalhes do Pokemon</h2>
          <PokemonCard
            name={selectedPokemon.name}
            image={selectedPokemon.image}
            type={selectedPokemon.type}
          />
          
          <button onClick={() => setSelectedPokemon(null)}>
           Voltar </button>
        </div>
      ) : (
        <div className="pokemon-list">
            {pokemonList.map((pokemon, index) => (
                <PokemonCard
                  key={index}
                  name={pokemon.name}
                  image={`https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${index + 1}.png`}
                  type="Desconhecido"
                  />
            ))}
        </div>
      ) }

</div>
      
  )
}

export default PokemonList;