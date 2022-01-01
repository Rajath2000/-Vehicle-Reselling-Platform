import React from "react";
import reactDom from "react-dom";

// function Greeding(){
//    return React.createElement(
//      'div',{},React.createElement(
//        'h1',{},'Hello'
//       )
//    );
   
// }

// function BookList(){
//   return(
//     <React.Fragment>
//       <Nest1/>
//       <Nest2/>
//     </React.Fragment>

//   );

// }


// const Nest1 = ()=>{
//   return(
//   <div className="c1">
//       <h1>Hello</h1>
//       <ul><a href="#">one</a></ul>
//     </div>
//   )
// }

// const Nest2= ()=>{
//    return(  <div className="c2">
//       <h1>Hello</h1>
//       <ul><a href="#">one</a></ul>
//     </div>
//    )

// }

const mobiles=[
  {
        name:"Realme C25Y (Metal Grey, 4GB RAM, 64GB Storage)" ,
        image:"https://m.media-amazon.com/images/I/41+r5uIAAAL._AC_UY327_FMwebp_QL65_.jpg",
        price:"₹10,624",
        description:"Lorem ipsum dolor sit amet consectetur adipisicing elit. Est excepturi suscipit alias earum similique laudantium nostrum nobis mollitia magni minus? Architecto cupiditate ex sed deleniti eveniet eius, aliquam laborum assumenda vel, ipsum possimus! Dicta, ex a quibusdam fugit alias aspernatur vero fuga, ut optio, animi similique iste. Eius, assumenda ratione."

  },
  {
        name:"Oppo A55 (Starry Black, 6GB RAM, 128GB Storage) with No Cost EMI/Additional Exchange Offers",
        image:"https://m.media-amazon.com/images/I/7125Jc1FDrL._AC_UY327_FMwebp_QL65_.jpg",
        price:"₹17,490",
        description:"Lorem ipsum dolor sit amet consectetur adipisicing elit. Est excepturi suscipit alias earum similique laudantium nostrum nobis mollitia magni minus? Architecto cupiditate ex sed deleniti eveniet eius, aliquam laborum assumenda vel, ipsum possimus! Dicta, ex a quibusdam fugit alias aspernatur vero fuga, ut optio, animi similique iste. Eius, assumenda ratione."

  },
  {
        name:"Realme C25Y (Metal Grey, 4GB RAM, 64GB Storage)" ,
        image:"https://m.media-amazon.com/images/I/41+r5uIAAAL._AC_UY327_FMwebp_QL65_.jpg",
        price:"₹10,624",
        description:"Lorem ipsum dolor sit amet consectetur adipisicing elit. Est excepturi suscipit alias earum similique laudantium nostrum nobis mollitia magni minus? Architecto cupiditate ex sed deleniti eveniet eius, aliquam laborum assumenda vel, ipsum possimus! Dicta, ex a quibusdam fugit alias aspernatur vero fuga, ut optio, animi similique iste. Eius, assumenda ratione."

  },
   {
        name:"Oppo A55 (Starry Black, 6GB RAM, 128GB Storage) with No Cost EMI/Additional Exchange Offers",
        image:"https://m.media-amazon.com/images/I/7125Jc1FDrL._AC_UY327_FMwebp_QL65_.jpg",
        price:"₹17,490",
        description:"Lorem ipsum dolor sit amet consectetur adipisicing elit. Est excepturi suscipit alias earum similique laudantium nostrum nobis mollitia magni minus? Architecto cupiditate ex sed deleniti eveniet eius, aliquam laborum assumenda vel, ipsum possimus! Dicta, ex a quibusdam fugit alias aspernatur vero fuga, ut optio, animi similique iste. Eius, assumenda ratione."

  },

]
function MobileComponent(){
  return(
     <div className="container">
       {mobiles.map((mobile)=>{
         return  (
         <Mobile mobile={mobile}>
        </Mobile> )
       })}
     
      </div>

  );
  
}

const Mobile = (props)=>{
  const{name,image,price,description}=props.mobile
  return(
    <>
     <div className="row ml-5 mr-5 mt-2">
      <div className="col-lg-2  col-sm-2">
        <Image 
        image={image}>
        </Image>
      </div>
      <div className="col-lg-10 mr-2 col-sm-10">
        <Description 
        name={name}
        price={price}
        description={description}
        >
        </Description>

      </div>
     </div>
    </>
  )
}

const Image=(props)=>{

  return(
    <img src={props.image} alt=""/>
  )
};

const Description=(props)=>{
  return(
    <>
    <h1>{props.name}</h1>
    <h5>{props.price}</h5>
    <p className="text-primary">FREE Delivery by Amazon</p>
    <p>{props.description}</p>
    </>
  )
}


reactDom.render(<MobileComponent />,document.getElementById('root'));