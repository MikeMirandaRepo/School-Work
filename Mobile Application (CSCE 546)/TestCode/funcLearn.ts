
// Named Function with Param and number return type 
function Sum(x: number, y: number): number{
	let sum = x+y;
	console.log(sum);
	return sum;
}
//Sum(2, 3);

//Anonymous Function
let anymAdd = function(x:number, y:number) : number{
	let sum = x+y;
	console.log(sum);
	return sum;
}
	
//anymAdd(4,5);

//optional Param for a function
function words(first: string, second?: string) : string{
	let sentence: string = first + ' ' + second;
	console.log(sentence);
	return sentence;
}

//words("Two ", "Words");
//words("One Word");


//Default Parameter
function optionalString(first: string, second: string = "Default Second") : string{
	let sentence: string = first + ' ' + second;
	console.log(sentence);
	return sentence;
}

