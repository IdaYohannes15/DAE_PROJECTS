// CONSTANT (JS2 requirement)
const SITE_NAME = "KIPO";

// Variables with different data types (JS1)
let totalGames = 3;
let newGamesComingSoon = true;
let websiteName = "KIPO";

// Array (JS2 requirement)
let gameList = ["Subway Surfers", "Temple Run", "Geometry Dash"];

// Mathematical operation (JS1)
let futureGameTotal = totalGames + 2;


// Custom function with multiple arguments and return (JS2)
function calculatePopularity(funScore, difficultyScore){
    return funScore * 10 - difficultyScore * 5;
}


// Function with if / else if / else (JS1 + JS2)
function rateGame(score){

    if(score > 70){
        return "Amazing Game!";
    }
    else if(score > 40){
        return "Pretty Good Game!";
    }
    else{
        return "Challenging Game!";
    }

}


// ONLOAD EVENT (JS2)
window.onload = function(){

    // Find element by ID (JS2)
    let title = document.getElementById("mainTitle");
    title.style.color = "yellow";


    // Console output (JS1)
    console.log("Welcome to " + SITE_NAME);


    // DOM output (JS1)
    let message = "Welcome to " + websiteName + "! We currently have " + totalGames + " games.";
    document.getElementById("gameMessage").innerText = message;


    // Find elements by CLASS (JS2)
    let gameCards = document.getElementsByClassName("game-card");


    // LOOP through elements (JS2)
    for(let i = 0; i < gameCards.length; i++){

        // onclick event
        gameCards[i].onclick = function(){

            let gameName = this.innerText;

            let playMessage;

            if(gameName.includes("Subway") || gameName.includes("Temple")){
                playMessage = "Great choice! " + gameName + " is very popular!";
            }
            else{
                playMessage = "Have fun playing " + gameName + "!";
            }

            console.log(playMessage);

            document.getElementById("gameMessage").innerText = playMessage;

        };


        // mouseover event
        gameCards[i].onmouseover = function(){
            this.style.transform = "scale(1.05)";
        };

    }


    // Find elements by TAG name (JS2)
    let paragraphs = document.getElementsByTagName("p");

    for(let i=0;i<paragraphs.length;i++){
        paragraphs[i].style.fontWeight = "bold";
    }


    // Attribute added to element (JS2)
    title.setAttribute("title","Welcome to the KIPO Game Portal");


    // Array iteration (JS2)
    for(let i=0;i<gameList.length;i++){
        console.log("Game Available: " + gameList[i]);
    }


    // Use custom function
    let score = calculatePopularity(9,5);
    console.log(rateGame(score));


    // TIMER (setInterval + clearInterval) (JS2)
    let counter = 0;

    let timer = setInterval(function(){

        console.log("KIPO site running...");

        counter++;

        if(counter > 5){
            clearInterval(timer);
        }

    },2000);

};