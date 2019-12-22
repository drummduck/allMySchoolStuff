using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Threading;
using BoggleClient;
using BoggleServer;

// Authors @ Namgi Yoon & Nathan Donaldson

namespace BoggleClientTest
{
    [TestClass]
    public class UnitTest1
    {
        Boggleserver server;
        private ManualResetEvent MRE;
        private ManualResetEvent MRE1;
        private ManualResetEvent MRE2;

        [TestMethod()]
        public void BC_ModelTest()
        {
            BoggleClient_Model test = new BoggleClient_Model();
            test.Disconnection();
        }

        [TestMethod()]
        public void ConnectionTest_EX()
        {
            server = new Boggleserver(80, @"X:\dictionary.txt");
            BoggleClient_Model test = new BoggleClient_Model();
            test.Connection("127.0.0.1", "test_name");
            test.Disconnection();
            server.stopServer();
        }

        [TestMethod()]
        public void ConnectionTest()
        {
            MRE = new ManualResetEvent(false);
            try
            {
                //setup server
                server = new Boggleserver(2, @"X:\dictionary.txt");

                //setup clients
                BoggleClient_Model test1 = new BoggleClient_Model();
                string IPAddress = "127.0.0.1";
                string name = "test";
    
                BoggleClient_Model test2 = new BoggleClient_Model();
                string name2 = "test2";


                test1.startAction += delegate(string line)
                {
                    MRE.Set();
                };

                //trigger event
                test1.Connection(IPAddress, name);
                test2.Connection(IPAddress, name2);

                Assert.AreEqual(true, MRE.WaitOne(1000), "Timed out waiting 1");

                test1.Disconnection();
                test2.Disconnection();
            }
            finally
            { server.stopServer(); }
        }
      
        [TestMethod()]
        public void StopTest()
        {
            MRE = new ManualResetEvent(false);
            MRE1 = new ManualResetEvent(false);
            
            try
            {
                //setup server
                server = new Boggleserver(1, @"X:\dictionary.txt");

                //setup clients
                BoggleClient_Model test1 = new BoggleClient_Model();
                string IPAddress = "127.0.0.1";
                string name = "test";

                BoggleClient_Model test2 = new BoggleClient_Model();
                string name2 = "test2";


                test1.startAction += delegate(string line)
                {                    
                    MRE.Set();
                };

                test1.endAction += delegate(string line)
                {
                    MRE1.Set();
                };

                //connect the clients
                test1.Connection(IPAddress, name);
                test2.Connection(IPAddress, name2);

                //trigger event
                Thread.Sleep(3000);

                Assert.AreEqual(true, MRE.WaitOne(50000), "Timed out waiting 1");
                Assert.AreEqual(true, MRE1.WaitOne(50000), "Timed out waiting 2");

                test1.Disconnection();
                test2.Disconnection();

            }
            finally
            {
                server.stopServer();
            }
        }

        [TestMethod()]
        public void TimeTest()
        {
            MRE = new ManualResetEvent(false);
            MRE1 = new ManualResetEvent(false);
            try
            {
                //setup server
                server = new Boggleserver(10, @"X:\dictionary.txt");

                //setup clients
                BoggleClient_Model test1 = new BoggleClient_Model();
                string IPAddress = "127.0.0.1";
                string name = "test";

                BoggleClient_Model test2 = new BoggleClient_Model();
                string name2 = "test2";

                test1.timeAction += delegate(string line)
                {
                    MRE.Set();
                };


                test2.timeAction += delegate(string line)
                {
                    MRE1.Set();
                };

                //connect the clients
                test1.Connection(IPAddress, name);
                test2.Connection(IPAddress, name2);

                //trigger event
                Thread.Sleep(1000);

                Assert.AreEqual(true, MRE.WaitOne(500), "Timed out waiting 1");
                Assert.AreEqual(true, MRE1.WaitOne(500), "Timed out waiting 2");

                test1.Disconnection();
                test2.Disconnection();

                
            }
            finally
            {
                server.stopServer();
            }

        }

        [TestMethod()]
        public void ScoreTest()
        {
            MRE = new ManualResetEvent(false);
            MRE1 = new ManualResetEvent(false);
            try
            {
                //setup server
                server = new Boggleserver(10, @"X:\dictionary.txt", "aahedsidglsdrvie");

                //setup clients
                BoggleClient_Model test1 = new BoggleClient_Model();
                string IPAddress = "127.0.0.1";
                string name = "test";

                BoggleClient_Model test2 = new BoggleClient_Model();
                string name2 = "test2";

               //connect the clients
                test1.Connection(IPAddress, name);
                test2.Connection(IPAddress, name2);
                
                // put actions
                test1.scoreAction += delegate(string line)
                {
                    MRE.Set();
                };


                test2.scoreAction += delegate(string line)
                {
                    MRE1.Set();
                };

                //trigger event
                test1.SendMessage("WORD aah");

                //trigger event
                Thread.Sleep(1000);

                Assert.AreEqual(true, MRE.WaitOne(500), "Timed out waiting 1");
                Assert.AreEqual(true, MRE1.WaitOne(500), "Timed out waiting 2");

                test1.Disconnection();
                test2.Disconnection();

                
            }
            finally
            {
                server.stopServer();
            }
        }
        
        //Error
        [TestMethod()]
        public void TerminateTest()
        {
            MRE = new ManualResetEvent(false);
            MRE1 = new ManualResetEvent(false);
            //setup server
                try
                {
                    server = new Boggleserver(10, @"X:\dictionary.txt");

                    //setup clients
                    BoggleClient_Model test1 = new BoggleClient_Model();
                    string IPAddress = "127.0.0.1";
                    string name = "test";

                    BoggleClient_Model test2 = new BoggleClient_Model();
                    string name2 = "test2";

                    test1.startAction += delegate(string line)
                    {
                        MRE.Set();
                    };


                    test2.terminateAction += delegate(string line)
                    {
                        MRE1.Set();
                    };

                    //connect the clients
                    test1.Connection(IPAddress, name);
                    test2.Connection(IPAddress, name2);

                    Thread.Sleep(1000);

                    //trigger event
                    test2.termination();

                    Assert.AreEqual(true, MRE.WaitOne(1000), "Timed out waiting 1");

                    test1.Disconnection();
                    test2.Disconnection();
                }
                finally
                {
                    
                    server.stopServer(); 
                }

        }
    }
}
