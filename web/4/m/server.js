let cart = {
    'lady1':{
	"count" : 0,
	},
    'kav2': {
	"count" : 0,
	},
    'rag3': {
	"count" : 0,
	},
    'ost4': {
	"count" : 0,
	},
    'bar5': {
	"count" : 0,
	},
    'red6': {
	"count" : 0,
	},
};

document.onclick = event => {
    if (event.target.classList.contains('plus')) {
        plusFunction(event.target.dataset.id);
    }
    if (event.target.classList.contains('minus')) {
        minusFunction(event.target.dataset.id);
    }
}

const plusFunction = id => {

    cart[id]['count']++;
	goodsCount(id);
    renderCart();
}

const minusFunction = id => {
    if (cart[id]['count'] - 1 < 0) {
	renderCart();
        return true;
    }
    cart[id]['count']--;
	goodsCount(id);
    renderCart();
}

const renderCart = () => {
    	console.log(cart);
}

renderCart();

const goodsCount = id => {
	var out = '';
	if(cart[id]['count']==0){
		out = ' ';
	}
	else{
    		out = cart[id]['count'];
	}
	document.getElementById(id).innerHTML = out;
}

