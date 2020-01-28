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

const ButtonPage: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonButton slot="start">
            <IonBackButton />
          </IonButton>
          <IonTitle class="ion-text-center">Ionic Title in a Toolbar</IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent className="ion-padding">
        <IonButton color="primary">
          This Is A Button
          <IonIcon slot="start" icon={star}></IonIcon>
        </IonButton>
      </IonContent>
    </IonPage>
  );
};

export default ButtonPage;