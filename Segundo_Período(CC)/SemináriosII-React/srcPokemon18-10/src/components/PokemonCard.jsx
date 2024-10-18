import './Pokemon.css'

function PokemonCard({name, type, image}){
    return(
    <div className='box'>
        <h2 className= {type}> {name}</h2>
        <img src= {image} alt={name}/>
        <p className = {type}>{type}</p>
        <br></br>
    </div>


    ) 
}
export default PokemonCard;