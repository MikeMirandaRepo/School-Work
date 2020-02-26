import {
  // a class is the def of an object w its variables and functions
  // an obj is an instance on a class
  // super calls the parent constructor
  IonCard,
  IonCardHeader,
  IonCardSubtitle,
  IonCardTitle,
  IonContent,
  IonHeader,
  IonIcon,
  IonRange,
  IonButton,
  IonItem,
  IonList,
  IonPage,
  IonTitle,
  IonItemSliding,
  IonToolbar
} from "@ionic/react";
import firebase from "firebase";
import { add, remove } from "ionicons/icons";
import React, { Component } from "react";
import { setUpNewOrders } from "../../redux/react-redux";
import { connect } from "react-redux";
import { db } from "../../App";
import { checkCurrentUser, handleSignOut } from "../../App";
import { toast } from "../../components/toast";

export interface IAppProps {
  history: any;
  location: any;
  match: any;
  staticContext: any;
  product: any;
  orderID: any;
  setUpNewOrders: any;
}

export interface IAppState {
  product: {
    name: string;
    price: number;
    category: string;
    imgURL: string;
    description: string;
    totalPrice: number;
    numItems: number;
    pID: string;
  };
  count: number;
}

const mapStateToProps = (state: any) => {
  return {
    products: state.products,
    orderID: state.orderID
  };
};

const mapDispatchToProps = (dispatch: any) => {
  return {
    setUpNewOrders: (order: any) => {
      dispatch(setUpNewOrders(order));
    }
  };
};

class ProductDetailPage extends React.Component<IAppProps, IAppState> {
  constructor(props: IAppProps) {
    super(props);
    console.log(this.props);
    this.state = {
      product: this.props.location.state.product,
      count: 1
    };
  }

  deleteProduct() {
    if (firebase.auth()) {
      db.collection("products")
        .doc(this.state.product.imgURL)
        .delete()
        .then(() =>
          toast(`${this.state.product.name} was succesfully deleted`)
        );
    } else {
      toast("You are not logged in to delete this item");
    }
  }

  _setStateValues(value: any): any {
    this.setState({ count: value });
  }

  _setUpNewOrders() {
    let date = new Date();
    let day = date.getDate();
    let month = date.getMonth();
    let year = date.getFullYear();
    this.props.setUpNewOrders({
      product: this.state.product,
      orderID: this.props.orderID,
      numItems: this.state.count,
      totalPrice: this.state.product.price * this.state.count,
      orderDate: `${month}/${day}/${year}`
    });
    toast("You have added an new Order");
  }

  pushNewOrder() {
    let date = new Date();
    let day = date.getDate();
    let month = date.getMonth();
    let year = date.getFullYear();
    let newOrder = {
      numItems: this.state.count,
      orderDate: `${month}/${day}/${year}`,
      orderID: this.props.orderID,
      totalPrice: this.state.product.price * this.state.count
    };

    this._setUpNewOrders();
    var uid: any;
    var user = firebase.auth().currentUser;
    if (user != null) {
      uid = user.uid;
    } else console.log("THE USER WAS NULL");
    db.collection("users")
      .doc(uid)
      .collection("orders")
      .add({ newOrder })
      .then();
  }

  render() {
    const { product } = this.state;
    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>Product Details</IonTitle>
            <IonButton slot="primary" onClick={() => this.pushNewOrder()}>
              Add Order
            </IonButton>
          </IonToolbar>
        </IonHeader>
        <IonContent>
          <IonList class="ion-text-center">
            <IonItemSliding>
              <IonCard>
                <IonCardHeader>
                  <IonCardTitle>{product.name}</IonCardTitle>
                  <IonCardSubtitle>
                    Item Category: {product.category}
                  </IonCardSubtitle>
                  <IonCardSubtitle>Price: {product.price}</IonCardSubtitle>
                </IonCardHeader>
                <img src={product.imgURL} />
              </IonCard>
            </IonItemSliding>
            <IonItem lines="none">
              <IonRange
                min={1}
                max={12}
                step={1}
                snaps={true}
                ticks={true}
                debounce={250}
                pin={true}
                onIonChange={e => this._setStateValues(e.detail.value)}
              >
                <IonIcon size="small" slot="start" icon={remove} />
                <IonIcon slot="end" icon={add} />
              </IonRange>
            </IonItem>
            <IonButton
              onClick={() => this.deleteProduct()}
              routerDirection="back"
              routerLink="/ProductListPage"
              slot="primary"
            >
              Remove Item
            </IonButton>
            <IonButton onClick={() => checkCurrentUser()}>Check User</IonButton>
          </IonList>
        </IonContent>
      </IonPage>
    );
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(ProductDetailPage);
