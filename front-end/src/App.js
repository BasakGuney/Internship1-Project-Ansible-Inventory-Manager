import logo from "./logo.svg";
import "./App.css";
import MyTreeView from "./treeview";
import {
  BrowserRouter as Router,
  Route,
  Switch,
  useLocation,
} from "react-router-dom";
import { ChakraProvider, Stack } from "@chakra-ui/react";
import {
  Tabs,
  TabList,
  TabPanels,
  Tab,
  Text,
  TabPanel,
  Button,
  Checkbox,
  Link,
  Menu,
  MenuIcon,
  MenuItem,
  MenuList,
  MenuDivider,
  MenuButton,
} from "@chakra-ui/react";
import { ChevronDownIcon } from "@chakra-ui/icons";
import { useEffect, useState } from "react";

function App() {
  const obj = {
    a: { b: { c: { g: "h" } }, p: { u: "l" } },
    d: { e: { f: { i: "k" } } },
  };
  const initialCheckedItems = { a: ["p"], d: [] };
  const [yamlText, setYamlText] = useState("");
  const label = { inputProps: { "aria-label": "Checkbox demo" } };
  const [clicked, setClicked] = useState(false);
  const [redirection, setRedirection] = useState("inventory");
  function submitFile() {
    var input = document.getElementById("formFileSm");
    const formData = new FormData();
    console.log(input.files[0]);
    formData.append("files", input.files[0]);
    formData.append("filename", input.files[0].name);
    fetch("/", {
      method: "POST",
      body: formData,
    });

    window.location = "/" + ("" + input.files[0].name).split(".zip")[0];
  }

  return (
    <>
      <Router>
        <Switch>
          <Route exact path="/">
            <ChakraProvider>
              <Tabs size="md" variant="enclosed">
                <TabList>
                  <Tab>Update Inventory</Tab>
                  <Tab>Create Inventory</Tab>
                </TabList>
                <TabPanels>
                  <TabPanel>
                    <Stack gap={0} direction="row" width="50%">
                      <input
                        class="form-control form-control-sm"
                        id="formFileSm"
                        type="file"
                        name="files"
                      />
                      <Button
                        size="sm"
                        colorScheme="facebook"
                        onClick={submitFile}
                      >
                        Submit
                      </Button>
                    </Stack>
                    <Tabs defaultIndex={0}>
                      <TabList>
                        <Tab>Hosts</Tab>
                        <Tab>Host Vars</Tab>
                        <Tab>Group Vars</Tab>
                      </TabList>

                      <TabPanels>
                        <TabPanel>
                          {Object.keys(obj).map((key) =>
                            typeof obj[key] == "object" ||
                            Array.isArray(obj[key]) ? (
                              <>
                                <Checkbox
                                  value={key + ":\n"}
                                  id={key}
                                  defaultChecked={
                                    initialCheckedItems[key] !== undefined
                                      ? true
                                      : false
                                  }
                                  onChange={() => {
                                    let text = "";
                                    Object.keys(obj).map((key) => {
                                      if (
                                        document.getElementById(key).checked
                                      ) {
                                        text =
                                          text +
                                          document.getElementById(key).value;
                                      }

                                      Object.keys(obj[key]).map((subKey) => {
                                        if (
                                          document.getElementById(
                                            key + "." + subKey
                                          ).checked
                                        ) {
                                          text =
                                            text +
                                            document.getElementById(
                                              key + "." + subKey
                                            ).value;
                                        }
                                      });
                                    });
                                    setYamlText(text);
                                  }}
                                >
                                  {key}
                                </Checkbox>
                                <br></br>
                                {Object.keys(obj[key]).map((subKey) =>
                                  typeof obj[key][subKey] == "object" ||
                                  Array.isArray(obj[key][subKey]) ? (
                                    <Stack pl={6} mt={1} spacing={1}>
                                      <Checkbox
                                        onChange={() => {
                                          let text = "";
                                          Object.keys(obj).map((key) => {
                                            if (
                                              document.getElementById(key)
                                                .checked
                                            ) {
                                              text =
                                                text +
                                                document.getElementById(key)
                                                  .value;
                                            }

                                            Object.keys(obj[key]).map(
                                              (subKey) => {
                                                if (
                                                  document.getElementById(
                                                    key + "." + subKey
                                                  ).checked
                                                ) {
                                                  text =
                                                    text +
                                                    document.getElementById(
                                                      key + "." + subKey
                                                    ).value;
                                                }
                                              }
                                            );
                                          });
                                          setYamlText(text);
                                        }}
                                        id={subKey}
                                        value={"\t" + obj[key][subKey]}
                                        defaultChecked={
                                          Array.isArray(
                                            initialCheckedItems[key]
                                          )
                                            ? initialCheckedItems[key].includes(
                                                subKey
                                              )
                                              ? true
                                              : false
                                            : false
                                        }
                                      >
                                        {subKey}
                                      </Checkbox>
                                    </Stack>
                                  ) : null
                                )}
                              </>
                            ) : null
                          )}
                          <Text value={yamlText}></Text>
                        </TabPanel>
                        <TabPanel></TabPanel>
                        <TabPanel></TabPanel>
                      </TabPanels>
                    </Tabs>
                  </TabPanel>
                  <TabPanel></TabPanel>
                </TabPanels>
              </Tabs>
            </ChakraProvider>
          </Route>
        </Switch>
      </Router>
    </>
  );
}

export default App;
