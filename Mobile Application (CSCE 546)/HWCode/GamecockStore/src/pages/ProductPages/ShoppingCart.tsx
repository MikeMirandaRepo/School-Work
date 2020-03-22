import {
  IonCardHeader,
  IonCardSubtitle,
  IonCardTitle,
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonCard,
  IonText,
  IonButton
} from "@ionic/react";
import React from "react";
import { connect } from "react-redux";
import { toast } from "../../components/toast";
import { checkCurrentUser, returnUserUID, db, isStoreOwner } from "../../App";
import { clearShoppingCart } from "../../redux/react-redux";
export interface IAppProps {
  shoppingProducts: [];
  products: any;
  watchOrders: any;
  clearShoppingCart:any ;
}

export interface IAppState {}
const mapStateToProps = (state: any) => {
  return {
    shoppingProducts: state.shoppingProducts,
    products: state.productsF
  };
};

const mapDispatchToProps = (dispatch: any) => {
    return {
      clearShoppingCart: () => {
        dispatch(clearShoppingCart());
      }
    };
};

class ShoppingCart extends React.Component<IAppProps, IAppState> {
  constructor(props: IAppProps) {
    super(props);
    this.state = {};
    //this.props.watchOrders();
  }
  async _confirmOrder() {
    if ((await checkCurrentUser()) !== null) {
      let date = new Date();
      let day = date.getDate();
      let month = date.getMonth();
      let year = date.getFullYear();
      let shoppingProducts = this.props.shoppingProducts;
      let orderPrice = 0;
      if (shoppingProducts.length === 0) {
        toast("Your Cart is Empty");
      } else {
        shoppingProducts.forEach((element: any) => {
          orderPrice += element.totalPrice;
          console.log(element);
        });
        let newOrder = {
          shoppingProducts,
          orderID: "",
          orderDate: "",
          orderPrice: 0
        };
        // this._setUpNewOrders();
        console.log(checkCurrentUser());
        var uid = returnUserUID();
        let dataList: any[] = [];
        console.log(newOrder);

        db.collection("users")
          .doc(uid)
          .get()
          .then(async (docRef: any) => {
            let data = await docRef.data();
            console.log(data);
            let index = 1;
            data.shopOrders.forEach((element: any) => {
              dataList.push(element);
              index++;
            });
            let newOrderID = index.toString();
            newOrder.orderID = newOrderID;
            newOrder.orderDate = `${month}/${day}/${year}`;
            newOrder.orderPrice = orderPrice;
            dataList.push(newOrder);
            console.log(newOrder);
            return dataList;
          })
          .then(async (listData: any) => {
            let data = await listData;
            let ifOwner = false;
            if (isStoreOwner()) ifOwner = true;
            console.log("The data is uploaded");
            db.collection("users")
              .doc(uid)
              .set({
                shopOrders: data,
                storeOwner: ifOwner
              })
              .then(this.props.clearShoppingCart());
          });
        toast("Order Successful");
      }
    } else {
      toast("There is No Logged In User to Add an Order");
    }
  }

  _createCardList(products: []) {
    return products.map((product: any) => {
      return (
        <IonCard className="card" key={product.pID}>
          <IonCardHeader>
            <IonCardTitle>{product.product.name}</IonCardTitle>
            <IonCardSubtitle>
              <IonText>Quantity: </IonText>
              {product.numItems}
            </IonCardSubtitle>
            <IonCardSubtitle>
              <IonText>Price: $</IonText>
              {product.totalPrice}
            </IonCardSubtitle>

            <IonCardSubtitle>{product.product.category} </IonCardSubtitle>
          </IonCardHeader>
        </IonCard>
      );
    });
  }

  render() {
    let productCards: any = this._createCardList(this.props.shoppingProducts);
    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>Shopping Cart</IonTitle>
          </IonToolbar>
        </IonHeader>
        <IonContent>
          <IonButton
            onClick={() => this._confirmOrder()}
            routerDirection="back"
            routerLink="/ProductListPage"
          >
            Confirm Order
          </IonButton>
          {productCards}
        </IonContent>
      </IonPage>
    );
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(ShoppingCart);
