from redmine import Redmine
redmine_url = 'http://172.20.0.250'
myapi_key = '8460b6cc8c06b87fca28292d0e15db5088a1058d'
ticket_author = 'adm.gleidson'
helpdesk_project_id = 'sr18_dd'
service = Redmine(redmine_url, key=myapi_key, impersonate=ticket_author)

newissue = service.issue.create(project_id = helpdesk_project_id,
                                TipoDemanda = 15,
                                subject ='Comunicado de Inconsistencia',
                                description ='TESTE INCRA',
                                due_date = "2017-01-10",
                                custom_fields= [{"id":"1","value":"ELANIA ANDRESA OLIVEIRA CRUZ"},
                                               {"id":"2","value":"PA SÃO LUIS"},
                                               {"id":"3","value":"PB0143000"},
                                               {"id":"4","value":"18"},
                                               {"id":"5","value":"45"},
                                               {"id":"6","value":"SOSSEGO"},
                                               {"id":"7","value":"teste@teste.com.br"},
                                               {"id":"8","value":"21 54879-8645"},
                                               {"id":"9","value":"61 7894-5613"}],
                                uploads=[{'path': '/home/luiz/Downloads/REDE.pdf'}])
                                "tracker_id":15,
                                )

"""
{"upload":null,
 "issue":{"_project_id":0,
          "TipoDemanda":15,
          "id":0,
          "project":null,
          "tracker":null,
          "status":null,
          "priority":null,
          "author":null,
          "assigned_to":null,
          "subject":"Comunicado de Inconsistencia",
          "status_id":0,
          "description":"teste",
          "start_date":"2016-12-12",
          "due_date":"2017-01-10",
          "closed_on":null,
          "lock_version":0,
          "done_ratio":0,
          "created_on":null,
          "updated_on":null,
          "custom_fields":[{"id":"1","value":"ELANIA ANDRESA OLIVEIRA CRUZ"},
                           {"id":"2","value":"PA SÃO LUIS"},
                           {"id":"3","value":"PB0143000"},
                           {"id":"4","value":"18"},
                           {"id":"5","value":"45"},
                           {"id":"6","value":"SOSSEGO"},
                           {"id":"7","value":"teste@teste.com.br"},
                           {id":"8","value":"21 54879-8645"},
                           {"id":"9","value":"61 7894-5613"}],
                            "uploads":[],
                            "project_id":85,
                            "tracker_id":15,
                            "priority_id":5,
                            "assigned_to_id":0},
          "errors":null,
          "trackers":null,
          "project":null,
          "issue_statuses":null}
"""
