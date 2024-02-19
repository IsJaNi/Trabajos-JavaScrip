const FIBONACCI = document.querySelector("#fibonacci")

FIBONACCI.addEventListener("submit", calcularSerie)
function calcularSerie(evt){
evt.preventDefault();

let a = parseInt(document.querySelector("#number").value);

if(number.value.length == 0){
  alert("No debe de quedar ningun campo vacio")
  return false
}

function fibonacci (f, a = 0, b = 1){
	if (f <= 0){	
		return [];
	}else if (f === 1){
		return [a];
	}else{
		return [a].concat(fibonacci (f - 1, b, a + b));
	}
}

const cantidad = parseInt (prompt("Ingrese nuevamente el valor ingresado anteriormente"))  
const resultado = fibonacci (cantidad);

let imprimir = document.getElementById("cantidad");
imprimir.textContent = `LOS PRIMEROS ${cantidad} NUMEROS DE LA SERIE FIBONACCI SON: ${resultado}`;
}