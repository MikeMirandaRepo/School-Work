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
  IonToolbar,
  IonAlert
} from "@ionic/react";
import firebase from "firebase";
import { add, remove, list } from "ionicons/icons";
import React, { Component } from "react";
import { setUpNewOrders, addShoppingProduct } from "../../redux/react-redux";
import { connect } from "react-redux";
import { checkCurrentUser, returnUserUID, db, isStoreOwner } from "../../App";
import { toast } from "../../components/toast";
import { resolve } from "url";
import { withRouter } from "react-router";

export interface IAppProps {
  history: any;
  location: any;
  match: any;
  staticContext: any;
  product: any;
  orderID: any;
  setUpNewOrders: any;
  addShoppingProduct: any;
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
  showAlert: boolean;
  showWarning: boolean;
  count: number;
}

const mapStateToProps = (state: any) => {
  return {
    products: state.productsF,
    orderID: state.orderID
  };
};

const mapDispatchToProps = (dispatch: any) => {
  return {
    setUpNewOrders: (order: any) => {
      dispatch(setUpNewOrders(order));
    },
    addShoppingProduct: (product: any) => {
      dispatch(addShoppingProduct(product));
    }
  };
};

class ProductDetailPage extends React.Component<IAppProps, IAppState> {
  constructor(props: IAppProps) {
    super(props);
    console.log(this.props);
    this.state = {
      product: this.props.location.state.product,
      count: 1,
      showAlert: false,
      showWarning: false
    };
  }

  async deleteProduct() {
    let bool = false;
    let isOwner = await isStoreOwner();
    console.log("User? " + isOwner);
    if ((await checkCurrentUser()) !== null) {
      try {
        if (isOwner) {
          db.collection("products")
            .doc(this.state.product.pID)
            .delete()
            .then(() => {
              console.log(`${this.state.product.name} was succesfully deleted`);
              bool = true;
            });
        } else {
          toast("The User is Not a Store Owner");
        }
      } catch (error) {
        console.log(error);
      }
    } else {
      toast("You are not logged in to delete this item");
    }
    console.log(bool);
    return bool;
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
      orderDate: `${month}/${day}/${year}`,
      pID: this.state.product.pID
    });

    toast("You have added an new Order");
  }

  _addToShoppingCart() {
    this.props.addShoppingProduct({
      product: this.state.product,
      numItems: this.state.count,
      totalPrice: this.state.product.price * this.state.count,
    });

    toast("You have added to your Shopping Cart");
  }

  async pushNewOrder() {
    if ((await checkCurrentUser()) !== null) {
      let date = new Date();
      let day = date.getDate();
      let month = date.getMonth();
      let year = date.getFullYear();
      let newOrder = {
        numItems: this.state.count,
        orderDate: `${month}/${day}/${year}`,
        orderID: this.props.orderID,
        totalPrice: this.state.product.price * this.state.count,
        pID: this.state.product.pID
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
          data.orders.forEach((element: any) => {
            dataList.push(element);
            console.log("index Before: " + index);
            index++;
            console.log("index after: " + index + " " + element);
          });
          newOrder.orderID = index.toString();
          dataList.push(newOrder);
          console.log(newOrder);
          return dataList;
        })
        .then(async (listData: any) => {
          let data = await listData;
          let ifOwner = false;
          if (isStoreOwner()) ifOwner = true;
          db.collection("users")
            .doc(uid)
            .set({
              orders: data,
              storeOwner: ifOwner
            });
        });
    } else {
      toast("There is No Logged In User to Add an Order");
    }
  }

  async _handleDelete() {
    const res = await this.deleteProduct();
    if (res) {
      this.props.history.replace("/ProductListPage", null);
    } else {
      console.log("Error Deleting Product");
    }
  }

  _showAlert(show: boolean) {
    this.setState({ showAlert: show });
  }
  _showWarning(show: boolean) {
    this.setState({ showWarning: show });
  }

  async _deleteProduct() {
    let isOwner = await isStoreOwner();
    if (isOwner) {
      this._showAlert(true);
    } else {
      this._showWarning(true);
    }
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
            <IonButton onClick={() => this._deleteProduct()} slot="primary">
              Remove Item
            </IonButton>
            <IonButton onClick={() => checkCurrentUser()}>Check User</IonButton>
          </IonList>
          <IonButton onClick={() => this._addToShoppingCart()} >
            Add to Shopping Cart
          </IonButton>
          <IonAlert
            isOpen={this.state.showAlert}
            onDidDismiss={() => this._showAlert(false)}
            header={"Are you sure you want to delete this product?"}
            buttons={[
              {
                text: "Yes",
                handler: () => {
                  this._handleDelete();
                  console.log("Confirm Product Delete");
                  this.props.history.goBack();
                }
              },
              {
                text: "No",
                handler: () => {
                  console.log("Product Delete Canceled");
                }
              }
            ]}
          />
          <IonAlert
            isOpen={this.state.showWarning}
            onDidDismiss={() => {
              this._showWarning(false);
            }}
            header={"You cannot delete products unless you are the store owner"}
            buttons={["Ok"]}
          />
        </IonContent>
      </IonPage>
    );
  }
}

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(withRouter(ProductDetailPage));
