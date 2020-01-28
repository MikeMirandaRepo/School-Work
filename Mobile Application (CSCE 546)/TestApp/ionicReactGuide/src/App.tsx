import React from 'react';
import { Redirect, Route } from 'react-router-dom';
import { IonApp, IonRouterOutlet } from '@ionic/react';
import { IonReactRouter } from '@ionic/react-router';
import Home from './pages/Home';
import ExampleRoute from "./pages/ExampleRoute";
import ButtonPage from "./pages/ButtonPage";
import ScrollableList from "./pages/ScrollableList";
import InputPage from "./pages/InputPage";
import LoginPage from "./pages/LoginPage";
import RegisterPage from "./pages/RegisterPage";





/* Core CSS required for Ionic components to work properly */
import '@ionic/react/css/core.css';

/* Basic CSS for apps built with Ionic */
import '@ionic/react/css/normalize.css';
import '@ionic/react/css/structure.css';
import '@ionic/react/css/typography.css';

/* Optional CSS utils that can be commented out */
import '@ionic/react/css/padding.css';
import '@ionic/react/css/float-elements.css';
import '@ionic/react/css/text-alignment.css';
import '@ionic/react/css/text-transformation.css';
import '@ionic/react/css/flex-utils.css';
import '@ionic/react/css/display.css';

/* Theme variables */
import './theme/variables.css';

const App: React.FC = () => (
  <IonApp>
    <IonReactRouter>
      <IonRouterOutlet>
        <Route path="/" component={Home} exact />
        <Route path="/ExampleRoute" component={ExampleRoute} exact />
        <Route path="/ButtonPage" component={ButtonPage} exact />
        <Route path="/ScrollableList" component={ScrollableList} exact />
        <Route path="/InputPage" component={InputPage} exact />
        <Route path="/LoginPage" component={LoginPage} exact />
        <Route path="/RegisterPage" component={RegisterPage} exact />
      </IonRouterOutlet>
    </IonReactRouter>
  </IonApp>
);

export default App;



// /*import React from 'react';
// import { Redirect, Route } from 'react-router-dom';
// import { IonApp, IonRouterOutlet } from '@ionic/react';
// import { IonReactRouter } from '@ionic/react-router';
// import Home from './pages/Home';

// import ExampleRoute from "./pages/ExampleRoute";



// /* Core CSS required for Ionic components to work properly */
// import '@ionic/react/css/core.css';

// /* Basic CSS for apps built with Ionic */
// import '@ionic/react/css/normalize.css';
// import '@ionic/react/css/structure.css';
// import '@ionic/react/css/typography.css';

// /* Optional CSS utils that can be commented out */
// import '@ionic/react/css/padding.css';
// import '@ionic/react/css/float-elements.css';
// import '@ionic/react/css/text-alignment.css';
// import '@ionic/react/css/text-transformation.css';
// import '@ionic/react/css/flex-utils.css';
// import '@ionic/react/css/display.css';

// /* Theme variables */
// import './theme/variables.css';

// const App: React.FC = () => (
//   <IonApp>
//     <IonReactRouter>
//       <IonRouterOutlet>
//         <Route path="/Home" component={Home} exact />
//         <Route path="/ExampleRoute" component={ExampleRoute} exact />
//         {/* <Route path="/ButtonPage" component={ButtonPage} exact />
//         <Route path="/ScrollableList" component={ScrollableList} exact />
//         <Route path="/InputPage" component={InputPage} exact /> */}
//       </IonRouterOutlet>
//     </IonReactRouter>
//   </IonApp>
// );

// export default App;
