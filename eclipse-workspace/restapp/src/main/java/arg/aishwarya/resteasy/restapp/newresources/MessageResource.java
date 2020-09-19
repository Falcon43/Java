package arg.aishwarya.resteasy.restapp.newresources;

import java.util.List;

import javax.ws.rs.Consumes;
import javax.ws.rs.DELETE;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.PUT;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import arg.aishwarya.resteasy.restapp.model.Message;
import arg.aishwarya.resteasy.service.MessageService;

@Path("/messages")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class MessageResource {
	
	MessageService messageService = new MessageService();
	
	
	@GET
	@Produces(MediaType.APPLICATION_XML)
	public List<Message> getMessages() {
		return messageService.getAllMessages();
	}

	@POST
	public Message addMessage(Message message) {
		return messageService.addMessage(message);
	}
	/*POST body raw input:
	{
    "author": "Padmé Amidala",
    "created": "2018-04-15T18:33:54.988+05:30",
    "message": "So this is how liberty dies. With thunderous applause."
	}
	{
    "author": "Obi-Wan Kenobi",
    "created": "2018-04-15T18:37:54.988+05:30",
    "message": "You were my brother, Anakin. I loved you."
	}
	{
    "author": "Anakin Skywalker",
    "created": "2018-04-15T18:37:54.988+05:30",
    "message": "Just for once, let me look on you with my own eyes"
	}
	* */
	
	@PUT
	@Path("/{messageId}")
	public Message updateMessage(@PathParam("messageId") long id, Message message) {
		message.setId(id);
		return messageService.updateMessage(message);
	}	
	
	@DELETE
	@Path("/{messageId}")
	public Message deleteMessage(@PathParam("messageId") long id) {
		return messageService.removeMessage(id);
	}
	
	@GET
	@Path("/{messageId}")
	public Message getMessage(@PathParam("messageId") long id) {
		return messageService.getMessage(id);
	}
	
}

