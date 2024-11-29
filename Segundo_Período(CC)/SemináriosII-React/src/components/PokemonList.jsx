import { useEffect, useState } from "react";
import PokemonCard from "./PokemonCard";

function PokemonList() {

  const handleCardClick = (pokemon)=> {
    setSelectedPokemon(pokemon);
    setIsLoading(true);
    setTimeout(function(){
      fetch(pokemon.url)
      .then((response) => response.json())
      .then((data) => {
        setSelectedPokemon(data);
        setIsLoading(false);
      })
      .catch((error) =>{
        console.error("Erro ao buscar os detalhes do Pokemon");
        setIsLoading(false);
      });
    })
  }

  const [selectedPokemon, setSelectedPokemon] = useState(null);
  const [pokemonList, setPokemonList] = useState([]);

  const [isLoading, setIsLoading] = useState(false);

  const [currentPage, setCurrentPage] = useState(1);
  const itemsPerPage = 20;

  const indexOfLastItem = currentPage * itemsPerPage;
  const indexOfFirstItem = indexOfLastItem - itemsPerPage;

  const currentPokemonList = pokemonList.slice(
    indexOfFirstItem,
    indexOfLastItem
  );

  const totalPages = Math.ceil(pokemonList.length / itemsPerPage);

  useEffect(() => {
    const fetchPokemonDetails = async () => {
      try {
        //Obtem os primeiros pokemons
        const response = await fetch("https://pokeapi.co/api/v2/pokemon?limit=151");
        const data = await response.json();

        //Busca os detalhes de cada pokemon
        const detailedPokemonList = await Promise.all(
          data.results.map(async (pokemon) => {
            const response = await fetch(pokemon.url);
            const details = await response.json();
            return {
              name: details.name,
              image: `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${details.id}.png`,
              type: details.types.map((typeInfo) => typeInfo.type.name).join("/")
            };
          })
        );

        //Atualiza o estado da lista completa de pokemons
        setPokemonList(detailedPokemonList);
      } catch (error) {
        console.error("Erro ao buscar os dados", error);
      }
    };

    fetchPokemonDetails();
  }, []);

  return (
    <div>
      {selectedPokemon ? (
        <div>
          <h2>Detalhes do Pokemon</h2>
          <PokemonCard
            name={selectedPokemon.name}
            image={selectedPokemon.image}
            type={selectedPokemon.type}
          />
          <button onClick={() => setSelectedPokemon(null)}>Voltar</button>
        </div>
      ) : (
        <>
          <div className="pokemon-list card">
            {currentPokemonList.map((pokemon, index) => (
              <PokemonCard
                key={index}
                name={pokemon.name}
                image={`https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${((currentPage - 1) * itemsPerPage) + index + 1}.png`}
                type=""
                onClick={() => handleCardClick(pokemon)}
              />
            ))}
          </div>
          <div className="pagination">
            <button
              onClick={() => setCurrentPage(currentPage - 1)}
              disabled={currentPage === 1}
            >
              Anterior
            </button>
            <span>Página {currentPage}</span>
            <button
              onClick={() => setCurrentPage(currentPage + 1)}
              disabled={currentPage === totalPages}
            >
              Próxima
            </button>
          </div>
        </>
      )}
    </div>
  );
}

export default PokemonList;