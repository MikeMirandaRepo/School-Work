import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonButton,
  IonBackButton,
} from "@ionic/react";
import React, { useState } from "react";

const ExampleRoute: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonButton slot="start">
            <IonBackButton />
          </IonButton>
          <IonTitle class="ion-text-center">This is the Example page</IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent className="ion-padding">
        {" "}
        <IonButton routerLink="/">Click to go to the Home Page</IonButton>
      </IonContent>
    </IonPage>
  );
};

export default ExampleRoute;
