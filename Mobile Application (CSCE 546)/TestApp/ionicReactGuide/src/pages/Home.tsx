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

const pages = [
  {
    name: "Button",
    path: "/ButtonPage"
  },
  {
    name: "ExampleRoute",
    desc: "/ExampleRoute"
  },
  {
    name: "Input",
    path: "/InputPage"
  },
  {
    name: "ScrollableList",
    path: "/ScrollableList"
  }
];

const Home: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle class="ion-text-center">Hub of All new Pages</IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent className="ion-padding">
        <IonList>
          {pages.map((element, i) => (
            <IonItemSliding>
              <IonButton routerLink={pages[i].path}>
                Click to go to the {pages[i].name} Page
              </IonButton>
            </IonItemSliding>
          ))}
        </IonList>
      </IonContent>
    </IonPage>
  );
};

export default Home;








