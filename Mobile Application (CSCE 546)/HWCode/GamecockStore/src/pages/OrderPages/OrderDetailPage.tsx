import {
  IonCardHeader,
  IonCardSubtitle,
  IonCardTitle,
  IonContent,
  IonHeader,
  IonItem,
  IonButton,
  IonList,
  IonItemSliding,
  IonPage,
  IonTitle,
  IonToolbar,
  IonCard,
  IonText
} from "@ionic/react";
import React from "react";
import { defaultOrders } from "../../redux/react-redux";
import { checkCurrentUser, returnUserUID, db, isStoreOwner } from "../../App";
import { toast } from "../../components/toast";

export interface IAppProps {
  location: any;
}

export interface IAppState {
  order: any;
}

export default class OrderDetailPage extends React.Component<
  IAppProps,
  IAppState
> {
  constructor(props: IAppProps) {
    super(props);
    console.log(this.props);
    this.state = { order: this.props.location.state.order };
  }

  mapStateToProps = (state: any) => {
    return {
      order: state.order
    };
  };

  async deleteStoreOrder() {
    if ((await checkCurrentUser()) !== null) {
      var uid = returnUserUID();
      let dataList: any[] = [];

      if (returnUserUID()) {
        db.collection("users")
          .doc(uid)
          .get()
          .then(async (docRef: any) => {
            let data = await docRef.data().shopOrders;
            let deletedOID = this.state.order.orderID;
            let index:number = 1
            data.forEach((element: any) => {
              if (parseInt(element.orderID, 10) !== deletedOID) {
                console.log(
                  "deleted Order ID: " +
                    deletedOID +
                    " and DB:" +
                    element.orderID
                );
                element.orderID = index
                index++
                dataList.push(element);
              } else {
                console.log(
                  "found the deleted Order ID: " +
                    deletedOID +
                    " and DB:" +
                    element.orderID
                );
              }
            });
            return dataList;
          })
          .then(async (listData: any) => {
            let data = await listData;
            let ifOwner = false;
            if (isStoreOwner()) ifOwner = true;
            db.collection("users")
              .doc(uid)
              .set({
                shopOrders: data,
                storeOwner: ifOwner
              });
            console.log(listData);
            toast(`You have deleted the Order`);
          });
      }
    }
    console.log(this.state.order);
  }
  checkState() {
    console.log(this.state.order);
  }

  _createCardList(products: any) {
    return products.map((product: any, index: any) => {
      return (
        <IonCard className="card" key={index}>
          <IonCardHeader>
            <IonCardTitle>
              Product: {product.product.name}
            </IonCardTitle>
            <IonCardSubtitle>
              Number of Products: {product.numItems}
            </IonCardSubtitle>
            <IonCardSubtitle>
              Total Price: ${product.totalPrice.toFixed(2)}
            </IonCardSubtitle>
          </IonCardHeader>
          <img src={product.product.imgURL} />
          <IonText>
            Description: {product.product.description}
          </IonText>
        </IonCard>
      );
    });
  }

  render() {
    let productCards: any = this._createCardList(this.state.order.shoppingProducts);

    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>Order Details</IonTitle>
            <IonButton
              slot="end"
              routerLink="/OrderListPage"
              routerDirection="back"
              onClick={() => this.deleteStoreOrder()}
            >
              Delete
            </IonButton>
          </IonToolbar>
        </IonHeader>
        <IonContent>
          <IonButton onClick={() => this.checkState()}>Check State</IonButton>
          {productCards}
        </IonContent>
      </IonPage>
    );
  }
}
