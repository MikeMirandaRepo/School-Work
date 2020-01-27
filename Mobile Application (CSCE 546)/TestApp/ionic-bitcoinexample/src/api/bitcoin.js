export const getBitcoinPrice = async (CurrencyType) => {
    try{
        const res = await 
        fetch(`https://api.coindesk.com/v1/bpi/currentprice/${CurrencyType}.json`);
        return await res.json();
    }catch(e){
        console.log(e)
    }

}