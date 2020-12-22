const firstName = prompt('First Name here: ');
const lastName = prompt('Last Name here: ');

const nameDisplayed = (fname, lname) => {
    return `Name: ${fname} ${lname}`;
}

alert(nameDisplayed(firstName, lastName));