const calculatePrice = (nbItems,unitPrice) => {
    let finalPrice = nbItems * unitPrice;
    return finalPrice;
}

const totalFishPrice = calculatePrice(5, 100);
console.log(totalFishPrice);