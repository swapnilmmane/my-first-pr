const express=require("express");
const app=express();
app.use(express.urlencoded());
app.use(express.static("."));
app.use(express.json());
app.get("/",(req,res)=>{
    res.sendFile(__dirname+"./index.html")
})
app.post("/api",(req,res)=>{
    console.log(req.body);
})
app.listen(3000,(err)=>{
    console.log("server started..");
})