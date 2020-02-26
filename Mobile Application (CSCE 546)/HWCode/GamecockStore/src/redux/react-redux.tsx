import { createStore, applyMiddleware } from "redux";
import firebase from "firebase";
import { db } from "../App";
export var products = [
  {
    name: "Mug",
    price: 9.99,
    category: "Apparel",
    imgURL:
      "http://t0.gstatic.com/images?q=tbn%3AANd9GcSASVnRhS-7urpmFzuC0F8Y_PeZ-aLpnTBcpmLMiL2wDBxcvGfm74sWwZPoaLobI_Uz88IIk-aD&usqp=CAc",
    description: "Its a Mug"
  },
  {
    name: "Jacket",
    price: 24.99,
    category: "Apperal",
    imgURL:
      "http://t0.gstatic.com/images?q=tbn%3AANd9GcSnFDfR0yI_WEVhW7JtzBxMUeWxoIGZ9nfNt2a17IBYuepG5BBlFkJSmZ4_5-H98jiyIv_z66M&usqp=CAc",
    description: "Its A Jacket"
  },
  {
    name: "Shirt",
    price: 19.99,
    category: "Apparel",
    imgURL:
      "https://fanatics.frgimages.com/FFImage/thumb.aspx?i=/productimages/_2531000/ff_2531193b_full.jpg&w=340",
    description: "Its a Shirt"
  },
  {
    name: "Hat",
    price: 12.99,
    category: "Apperal",
    imgURL:
      "http://t0.gstatic.com/images?q=tbn%3AANd9GcQorY8CgdcFeiiTa60B5E3y-GGWhqMFqXCy0XuqH2jUSIJ3iG2GbAowhLYpjZI&usqp=CAc",
    description: "Its A Hat"
  },
  {
    name: "Tumbler",
    price: 34.99,
    category: "Toy",
    imgURL:
      "http://t0.gstatic.com/images?q=tbn%3AANd9GcTlAv484m7340x1hv8Ts8ZP0zXjAA4X4gTaUOxXK7MB4IHOZWhj7ef196qvardYymzEG1_67Tk&usqp=CAc",
    description: "Its A Cup"
  }
];

export var orders = [
  {
    orderID: "1",
    numItems: 3,
    totalPrice: 24.99,
    orderDate: "3-5-19"
  },
  {
    orderID: "2",
    numItems: 4,
    totalPrice: 34.99,
    orderDate: "4-6-19"
  },
  {
    orderID: "3",
    numItems: 1,
    totalPrice: 44.99,
    orderDate: "5-7-19"
  },
  {
    orderID: "4",
    numItems: 5,
    totalPrice: 54.99,
    orderDate: "6-8-19"
  },
  {
    orderID: "5",
    numItems: 6,
    totalPrice: 84.99,
    orderDate: "7-9-19"
  }
];

//
// Initial State
//

const initialState: any = {
  productsF: [],
  ordersF: [],
  products: products,
  orders: orders,
  orderID: orders.length,
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

const store = createStore(reducer, applyMiddleware());
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

export const setUser = (user: any) => {
  return {
    type: "setUser",
    value: user
  };
};

export const watchProducts = () => {
  return function(dispatch: any) {
    db.collection("users")
      .doc(initialState.currentUser.currentUser.uid)
      .onSnapshot(function(doc: any) {
        var productData: any = doc.data().products;
        let ProductPromises = productData.map((product: any) => {
          return db
            .collection("products")
            .doc(product)
            .get();
        });
        Promise.all(ProductPromises).then((productDocs: any) => {
          let returnProducts = productDocs.map((productDocs: any) => {
            return productDocs.data();
          });
          dispatch(firebaseProducts(returnProducts));
        });
      });
  };
};

export const watchOrders = () => {
  return function(dispatch: any) {
    db.collection("users")
      .doc(initialState.currentUser.currentUser.uid)
      .onSnapshot(function(doc: any) {
        var orderData: any = doc.data().orders;
        let OrderPromises = orderData.map((order: any) => {
          return db
            .collection("orders")
            .doc(order)
            .get();
        });
        Promise.all(OrderPromises).then((orderDocs: any) => {
          let returnOrders = orderDocs.map((orderDocs: any) => {
            return orderDocs.data();
          });
          dispatch(firebaseOrders(returnOrders));
        });
      });
  };
};
