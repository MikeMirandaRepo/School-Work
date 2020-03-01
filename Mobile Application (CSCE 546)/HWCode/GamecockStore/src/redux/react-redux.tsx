import { createStore, applyMiddleware } from "redux";
import { db, checkCurrentUser } from "../App";
import { toast } from "../components/toast";
import thunkMiddleware from "redux-thunk";

export var defaultProducts = [
  {
    name: "Mug",
    price: 9.99,
    category: "Apparel",
    imgURL:
      "http://t0.gstatic.com/images?q=tbn%3AANd9GcSASVnRhS-7urpmFzuC0F8Y_PeZ-aLpnTBcpmLMiL2wDBxcvGfm74sWwZPoaLobI_Uz88IIk-aD&usqp=CAc",
    description: "Its a Mug",
    pID: "wSIc85UbGLx5tlZBnHKC"
  },
  {
    name: "Jacket",
    price: 24.99,
    category: "Apperal",
    imgURL:
      "http://t0.gstatic.com/images?q=tbn%3AANd9GcSnFDfR0yI_WEVhW7JtzBxMUeWxoIGZ9nfNt2a17IBYuepG5BBlFkJSmZ4_5-H98jiyIv_z66M&usqp=CAc",
    description: "Its A Jacket",
    pID: "MFV8qN9gyvRfrNi2ik5G"
  },
  {
    name: "Shirt",
    price: 19.99,
    category: "Apparel",
    imgURL:
      "https://fanatics.frgimages.com/FFImage/thumb.aspx?i=/productimages/_2531000/ff_2531193b_full.jpg&w=340",
    description: "Its a Shirt",
    pID: "9Se1atQ3mibsfWpUrlxK"
  },
  {
    name: "Hat",
    price: 12.99,
    category: "Apperal",
    imgURL:
      "http://t0.gstatic.com/images?q=tbn%3AANd9GcQorY8CgdcFeiiTa60B5E3y-GGWhqMFqXCy0XuqH2jUSIJ3iG2GbAowhLYpjZI&usqp=CAc",
    description: "Its A Hat",
    pID: "naT9s2nFHN6cBHte6Lus"
  },
  {
    name: "Tumbler",
    price: 34.99,
    category: "Toy",
    imgURL:
      "http://t0.gstatic.com/images?q=tbn%3AANd9GcTlAv484m7340x1hv8Ts8ZP0zXjAA4X4gTaUOxXK7MB4IHOZWhj7ef196qvardYymzEG1_67Tk&usqp=CAc",
    description: "Its A Cup",
    pID: "mdvltve0Z0oxC0s6atBw"
  }
];
export var defaultProductIDs = [
  "9Se1atQ3mibsfWpUrlxK",
  "MFV8qN9gyvRfrNi2ik5G",
  "mdvltve0Z0oxC0s6atBw",
  "naT9s2nFHN6cBHte6Lus",
  "wSIc85UbGLx5tlZBnHKC"
];

export var defaultOrderIDs = [
  "ZBYKpVquI68ZclDYc4U3",
  "9wgmBDb0TLW2rhe8e8Yw",
  "FB3KmMPYwtNnzprhSfe7",
  "FZc0fzRrP7kwugbUgIqm",
  "m0MmGkrWu32K0JLNdF6w"
];
export var defaultOrders = [
  {
    orderID: "1",
    numItems: 3,
    totalPrice: 24.99,
    orderDate: "3-5-19",
    pID: "ZBYKpVquI68ZclDYc4U3"
  },
  {
    orderID: "2",
    numItems: 4,
    totalPrice: 34.99,
    orderDate: "4-6-19",
    pID: "9wgmBDb0TLW2rhe8e8Yw"
  },
  {
    orderID: "3",
    numItems: 1,
    totalPrice: 44.99,
    orderDate: "5-7-19",
    pID: "FB3KmMPYwtNnzprhSfe7"
  },
  {
    orderID: "4",
    numItems: 5,
    totalPrice: 54.99,
    orderDate: "6-8-19",
    pID: "FZc0fzRrP7kwugbUgIqm"
  },
  {
    orderID: "5",
    numItems: 6,
    totalPrice: 84.99,
    orderDate: "7-9-19",
    pID: "m0MmGkrWu32K0JLNdF6w"
  }
];

//
// Initial State
//

const initialState: any = {
  productsF: [],
  ordersF: [],
  products: defaultProducts,
  orders: defaultOrders,
  orderID: defaultOrders.length + 1,
  currentUser: null
};

//
// Reducer
//

const reducer = (state = initialState, action: any) => {
  switch (action.type) {
    case "setUpNewOrders":
      let newOrder = state.orders;
      newOrder.push(action.value);
      return {
        ...state,
        orderID: state.orderID + 1,
        orders: newOrder
      };
    case "setUpNewProducts":
      let newProduct = state.products;
      newProduct.push(action.value);
      return {
        ...state,
        products: newProduct
      };
    case "firebaseProducts":
      return { ...state, productsF: action.value };

    case "firebaseOrders":
      return { ...state, ordersF: action.value };

    default:
      return state;
  }
};

//
// Store
//

const store = createStore(reducer, applyMiddleware(thunkMiddleware));
export { store };

//
// Action Creator
//

export const setUpNewOrders = (newOrder: any) => {
  return {
    type: "setUpNewOrders",
    value: newOrder
  };
};

export const setUpNewProducts = (newProduct: any) => {
  return {
    type: "setUpNewProducts",
    value: newProduct
  };
};

export const firebaseProducts = (firebaseProducts: any) => {
  return {
    type: "firebaseProducts",
    value: firebaseProducts
  };
};

export const firebaseOrders = (firebaseOrders: any) => {
  return {
    type: "firebaseOrders",
    value: firebaseOrders
  };
};

export const watchProducts = () => {
  return function(dispatch: any) {
    db.collection("products").onSnapshot(productDocs => {
      var products = productDocs.docs.map((productDoc: any) => {
        var product = productDoc.data();
        return product;
      });
      dispatch(firebaseProducts(products));
    });
  };
};

export const watchOrders = (user: any) => {
  return function(dispatch: any) {
    if (!user) {
    } else {
      console.log("USER: " + user)
      db.collection("users")
        .doc(user)
        .onSnapshot(async function(doc: any) {
          const orders = await doc.data().orders;
          console.log("ORDERS:" + orders);
          orders.forEach((element:any) => {
            console.log(element.numItems)
          });
          let orderProductsPromises = orders.map((currOrd: any) => {
            console.log(currOrd)
            return db
              .collection("products")
              .doc(currOrd.pID)
              .get();
          });

          Promise.all(orderProductsPromises)
            .then((productDocs: any) => {
              return productDocs.map((product: any) => {
                return product.data();
              });
            })
            .then((products: any) => {
              let finalOrders = orders.map((currOrder: any, index: number) => {
                return {
                  numItems: currOrder.numItems,
                  totalPrice: currOrder.totalPrice,
                  orderDate: currOrder.orderDate,
                  pID: products[index],
                  orderID: index + 1
                };
              });
              dispatch(firebaseOrders(finalOrders));
            });
        });
    }
  };
};
