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

  render() {
    const { order } = this.state;
    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>Order Details</IonTitle>
            <IonButton slot="primary" onClick={() => console.log(this.state)}>
              Check State
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
