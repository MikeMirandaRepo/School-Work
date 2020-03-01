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
  IonToolbar
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
            let data = await docRef.data().orders;
            let deletedOID = this.state.order.orderID;
            data.forEach((element: any) => {
              if (parseInt(element.orderID, 10) !== deletedOID) {
                console.log(
                  "deleted Order ID: " +
                    deletedOID +
                    " and DB:" +
                    element.orderID
                );
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
                orders: data,
                storeOwner: ifOwner
              });
            console.log(listData);
            toast(`You have deleted the Order`);
          });
      }
    }
    console.log(this.state.order);
  }

  render() {
    const { order } = this.state;
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
          <IonList class="ion-text-center">
            <IonItemSliding>
              <IonItem lines="full">
                <IonCardHeader>
                  <IonCardTitle>Order ID: {order.orderID}</IonCardTitle>
                  <IonCardSubtitle>
                    Date Ordered: {order.orderDate}
                  </IonCardSubtitle>
                  <IonCardSubtitle>
                    Order Count: {order.numItems}
                  </IonCardSubtitle>
                  <IonCardSubtitle>
                    Total Price: {order.totalPrice}
                  </IonCardSubtitle>
                </IonCardHeader>
              </IonItem>
            </IonItemSliding>
          </IonList>
        </IonContent>
      </IonPage>
    );
  }
}
