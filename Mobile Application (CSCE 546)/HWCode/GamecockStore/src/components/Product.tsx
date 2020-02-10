
const imgURLDefault: string =
  "https://www.foragegroup.com/public/images/noim.png";
export class Product {
  name: string;
  price: string;
  category: string;
  imgURL?: string;

  constructor(name: string, price: string, category: string, imgURL?: string) {
    this.name = name;
    this.price = price;
    this.category = category;
    if (imgURL == null) this.imgURL = imgURLDefault;
    else this.imgURL = imgURL;
  }
}
