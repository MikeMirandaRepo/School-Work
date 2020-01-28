import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonItemOption,
  IonAvatar,
  IonToolbar,
  IonList,
  IonItem, 
  IonText,
  IonLabel,
  IonItemSliding,
  IonItemOptions,
  IonButton,
  IonIcon,
  IonBackButton,
  IonInput
} from "@ionic/react";
import React, { useState } from "react";
import { star } from "ionicons/icons";

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
        <IonButton routerLink="/home">Click to go to the Home Page</IonButton>
      </IonContent>
    </IonPage>
  );
};

export default ExampleRoute;
